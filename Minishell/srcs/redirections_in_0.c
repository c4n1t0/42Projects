/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_in_0.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:52:24 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/27 18:20:55 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_prepare_redirection_in(t_redirect *redir, t_ms_data *ms_data,
		char *gnl)
{
	redir->q = redir->p +1;
	if (*redir->q == '<')
	{
		redir->mode = 1;
		redir->q++;
	}
	if (*redir->q == '<')
	{
		redir->mode = 2;
		redir->q++;
	}
	while (*redir->q == ' ')
		redir->q++;
	ms_data->infile = ft_calloc(sizeof(char), ft_strlen(gnl));
	while (ft_isalnum(*redir->q) != 0 || *redir->q == '"' || *redir->q == 39
		|| *redir->q == '/' || *redir->q == '-' || *redir->q == '_' || *redir->q
		== '$' || (*redir->q == ' '
			&& ft_quote_pipe(ms_data->infile, redir->q) != 0))
	{
		ms_data->infile[redir->i] = *redir->q;
		redir->q++;
		redir->i++;
	}
	ms_data->infile[redir->i] = '\0';
	ms_data->infile = ft_remove_quote(ms_data->infile);
}

int	ft_heredoc_simple(t_ms_data *ms_data, char *gnl)
{
	int	fd_pipe[2];
	int	status;

	pipe(fd_pipe);
	ms_data->pid_pr = fork();
	if (ms_data->pid_pr == -1)
	{
		ft_signal_cmd(1, ms_data);
		perror("minihsell: Error cmd_fork process");
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
	return (0);
}

int	ft_type_redirection_in(t_redirect *redir, t_ms_data *ms_data, char *gnl)
{
	if (redir->mode == 2)
	{
		ft_infile_triple_redirection(ms_data->infile, ms_data);
		ms_data->fd_in = ft_open_infile("temp", ms_data);
		if (ms_data->fd_in == -1)
			return (free(ms_data->infile), 1);
	}
	else if (redir->mode == 1)
	{
		if (ft_heredoc_simple(ms_data, gnl) == 1)
			return (free (gnl), 1);
		ms_data->status_sig = 0;
	}
	else
	{
		ms_data->fd_in = ft_open_infile(ms_data->infile, ms_data);
		if (ms_data->fd_in == -1)
			return (free(ms_data->infile), 1);
	}
	return (free(ms_data->infile), 0);
}

void	ft_init_redirect_value_in(t_redirect *redir, t_ms_data *ms_data,
		char *gnl, char c)
{
	if (ms_data->fd_in != 1)
		close(ms_data->fd_in);
	redir->mode = 0;
	redir->i = 0;
	redir->p = ft_strchr_pipes(gnl, c);
}

char	*ft_remove_redirection_in(char *gnl, t_ms_data *ms_data)
{
	t_redirect	redir;

	ft_init_redirect_value_in(&redir, ms_data, gnl, '<');
	if (ft_check_redirection_in(redir.p, ms_data) == 1)
		return (free (gnl), NULL);
	ft_prepare_redirection_in(&redir, ms_data, gnl);
	if (ft_type_redirection_in(&redir, ms_data, gnl) != 0)
		return (NULL);
	while (*redir.q != '\0')
	{
		*redir.p = *redir.q;
		redir.p++;
		redir.q++;
	}
	*redir.p = '\0';
	return (gnl);
}
