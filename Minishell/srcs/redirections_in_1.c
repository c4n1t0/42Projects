/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_in_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:31:38 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/27 18:48:15 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_open_infile(char *filename, t_ms_data *ms_data)
{	
	int	fd;

	if (ms_data->status_sig == 1)
		return (-1);
	if (access(filename, F_OK) == -1)
	{
		write(2, "minishell: ", 11);
		perror(filename);
		ft_signal_cmd(1, ms_data);
		return (-1);
	}
	else
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
		{
			write(2, "minishell: ", 11);
			perror(filename);
			ft_signal_cmd(1, ms_data);
		}
		return (fd);
	}
}

void	ft_redirection_error_in(int i, int nbr, t_ms_data *ms_data)
{
	if (i == 1)
	{
		if (nbr == 4)
			ft_putstr_fd("minishell: syntax error near unexpected token `<'\n",
				2);
		else if (nbr == 5)
			ft_putstr_fd("minishell: syntax error near unexpected token `<<'\n",
				2);
		else
			ft_putstr_fd("minishell: syntax error near unexpected token `<<<'\n",
				2);
	}
	if (i == 2)
		ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n",
			2);
	ft_signal_cmd(258, ms_data);
}

void	ft_prepare_dred_in(char *gnl, t_ms_data *ms_data)
{
	char	*q;
	char	*p;
	int		i;

	i = 0;
	p = ft_strchr(gnl, '<');
	q = p;
	q++;
	if (*q == '<')
		q++;
	while (*q == ' ')
		q++;
	ms_data->infile = ft_calloc(sizeof(char), ft_strlen(gnl));
	while ((ft_isalnum(*q) != 0) || *q == '"' || *q == 39
		|| *q == '/' || *q == '-' || *q == '_' || *q == '$'
		|| (*q == ' ' && ft_quote_pipe(ms_data->infile, q) != 0))
	{
		ms_data->infile[i] = *q;
		q++;
		i++;
	}
	ms_data->infile[i] = '\0';
	ms_data->infile = ft_remove_quote(ms_data->infile);
}

char	*ft_infile_loop(int status, t_ms_data *ms_data, char *str, char *instr)
{
	while (status != 1 && ft_strncmp(str, ms_data->infile,
			(ft_strlen(ms_data->infile) + 1)) != 0)
	{
		instr = ft_free_and_join(instr, str);
		instr = ft_free_and_join(instr, "\n");
		free(str);
		str = readline(">");
		if (!str || ft_strncmp(str, ms_data->infile,
				(ft_strlen(ms_data->infile) + 1)) == 0)
		{
			status = 1;
			free(str);
		}
	}
	return (instr);
}

void	ft_infile_double_redirection(t_ms_data *ms_data, char *gnl)
{
	char	*str;
	char	*instr;
	int		status;

	status = 0;
	instr = ft_calloc(1, sizeof(char *));
	if (ms_data->pipe == 1)
		ft_prepare_dred_in(gnl, ms_data);
	str = readline(">");
	if (!str)
	{
		free (str);
		status = 1;
	}
	instr = ft_infile_loop(status, ms_data, str, instr);
	ms_data->fd_in = open("temp", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR
			| S_IRGRP | S_IWGRP | S_IROTH);
	ft_putstr_fd(instr, ms_data->fd_in);
	return (close(ms_data->fd_in), free (instr));
}
