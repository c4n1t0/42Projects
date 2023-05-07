/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_in_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:57:17 by bjimenez          #+#    #+#             */
/*   Updated: 2022/12/27 18:10:18 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_value_redirection(t_ms_data *ms_data)
{
	ms_data->fd_blt = 1;
	ms_data->fd_in = 1;
	ms_data->redirection_status = 0;
	ms_data->infile = NULL;
	ms_data->outfile = NULL;
	ms_data->pipe = 0;
	ms_data->status_sig = 0;
}

void	ft_dred_file_dup(char *aux, char *str)
{
	free (aux);
	aux = ft_strdup(str);
}

char	*ft_dred_file(char *gnl, t_ms_data *ms_data)
{
	char	**aux;
	char	*temp;
	int		i;

	aux = ft_split(gnl, ' ');
	free (gnl);
	gnl = ft_strdup("");
	i = -1;
	temp = ft_strjoin("<<", ms_data->infile);
	while (aux[++i])
	{
		if (!ft_strncmp(temp, aux[i], ft_strlen(temp)))
			ft_dred_file_dup(aux[i], "<temp");
		else if (!ft_strncmp("<<", aux[i], ft_strlen(aux[i])))
			ft_dred_file_dup(aux[i], "<");
		else if (!ft_strncmp(ms_data->infile, aux[i], ft_strlen(aux[i])))
			ft_dred_file_dup(aux[i], "temp");
		gnl = ft_wld_strjoin(gnl, aux[i]);
		gnl = ft_wld_strjoin(gnl, " ");
	}
	return (free_split (aux), free (temp), gnl);
}

int	ft_detec_dr(char *gnl)
{
	int		i;
	int		n_dr;
	char	**split;

	i = -1;
	n_dr = 0;
	split = ft_split(gnl, ' ');
	while (split[++i] && n_dr == 0)
		if (split[i][0] == '<' && split[i][1] == '<' && split[i][2] != '<')
			n_dr++;
	free_split(split);
	return (n_dr);
}

int	ft_heredoc_pipe(t_ms_data *ms_data, char *gnl)
{
	int		fd_pipe[2];
	int		status;

	pipe(fd_pipe);
	ms_data->pid_pr = fork();
	if (ms_data->pid_pr == -1)
	{
		ft_signal_cmd(1, ms_data);
		perror("minishell: Error cmd_fork process");
	}
	else if (ms_data->pid_pr == 0)
	{
		ft_infile_double_redirection(ms_data, gnl);
		exit(0);
	}
	else
	{
		waitpid(ms_data->pid_pr, &status, 0);
		if (WIFEXITED(status))
			ft_signal_cmd(WEXITSTATUS(status), ms_data);
		ms_data->fd_in = ft_open_infile("temp", ms_data);
		if (ms_data->fd_in == -1 && !WIFEXITED(status))
			return (free(ms_data->infile), 1);
	}
	return (free(ms_data->infile), 0);
}
