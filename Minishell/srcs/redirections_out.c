/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_out.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 00:18:37 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/20 18:09:16 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redirection_error_out(int i, int nbr, t_ms_data *ms_data)
{
	if (i == 1)
	{
		if (nbr <= 3)
			ft_putstr_fd("minishell: syntax error near unexpected token `>'\n",
				2);
		else
			ft_putstr_fd("minishell: syntax error near unexpected token `>>'\n",
				2);
	}
	if (i == 2)
		ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n",
			2);
	ft_signal_cmd(2, ms_data);
}

int	ft_check_redirection_out(char *p, t_ms_data *ms_data)
{
	int	i;

	i = 0;
	while (*p == '>')
	{
		p++;
		i++;
	}
	if (i > 2)
		return (ft_redirection_error_out(1, i, ms_data), 1);
	while (*p != '\0')
	{
		if (ft_isalnum(*p) != 0 || *p == '/' || *p == '-' || *p == '_')
			return (0);
		if (*p == '>')
			return (ft_redirection_error_out(1, i, ms_data), 1);
		p++;
	}
	return (ft_redirection_error_out(2, i, ms_data), 1);
}

void	ft_init_redirect_value(t_redirect *redir, t_ms_data *ms_data, char *gnl,
		char c)
{
	if (ms_data->fd_blt != 1)
		close(ms_data->fd_blt);
	redir->mode = 0;
	redir->i = 0;
	redir->p = ft_strchr_pipes(gnl, c);
}

void	ft_save_redirect_file(t_redirect *redir, t_ms_data *ms_data, char *gnl)
{
	redir->q = redir->p;
	redir->q++;
	if (*redir->q == '>')
	{
		redir->mode = 1;
		redir->q++;
	}
	while (*redir->q == ' ')
		redir->q++;
	ms_data->outfile = ft_calloc(sizeof(char), ft_strlen(gnl));
	while ((ft_isalnum(*redir->q) != 0) || *redir->q == '"' || *redir->q == 39
		|| *redir->q == '/' || *redir->q == '-' || *redir->q == '_'
		|| (*redir->q == ' ' && ft_quote_pipe(ms_data->outfile, redir->q) != 0))
	{
		ms_data->outfile[redir->i] = *redir->q;
		redir->q++;
		redir->i++;
	}
	ms_data->outfile[redir->i] = '\0';
}

char	*ft_remove_redirection_out(char *gnl, t_ms_data *ms_data)
{
	t_redirect	redir;

	ft_init_redirect_value(&redir, ms_data, gnl, '>');
	if (ft_check_redirection_out(redir.p, ms_data) == 1)
		return (NULL);
	ft_save_redirect_file(&redir, ms_data, gnl);
	ms_data->outfile = ft_remove_quote(ms_data->outfile);
	if (redir.mode == 1)
		ms_data->fd_blt = open(ms_data->outfile, O_WRONLY | O_CREAT | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	else
		ms_data->fd_blt = open(ms_data->outfile, O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	while (*redir.q != '\0')
	{
		*redir.p = *redir.q;
		redir.p++;
		redir.q++;
	}
	*redir.p = '\0';
	return (free (ms_data->outfile), gnl);
}
