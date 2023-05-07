/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile_and_outfile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:26:12 by bjimenez          #+#    #+#             */
/*   Updated: 2022/12/22 10:23:08 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_outfile_arg(char *gnl, t_ms_data *ms_data)
{
	pid_t	pid_pr;
	int		status;

	pid_pr = fork();
	if (pid_pr == -1)
	{
		perror("Error cmd_fork process");
		ft_signal_cmd(1, ms_data);
	}
	else if (pid_pr > 0)
	{
		waitpid(pid_pr, &status, 0);
		if (WIFEXITED(status))
			ft_signal_cmd(WEXITSTATUS(status), ms_data);
	}
	else
	{
		dup2(ms_data->fd_blt, 1);
		ft_ex_cmd(gnl, g_ms_data->envp, ms_data);
	}
	close (ms_data->fd_blt);
}

void	ft_pipe2(char *cmd, char **envp, int fd, t_ms_data *ms_data)
{
	pid_t	pid;
	int		fd_pipe[2];

	pipe(fd_pipe);
	pid = fork();
	if (pid == -1)
		perror("Error fork process");
	else if (pid > 0)
	{
		close(fd_pipe[1]);
		dup2(fd_pipe[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(fd_pipe[0]);
		dup2(fd_pipe[1], 1);
		if (fd == 0)
			exit(1);
		else
			ft_ex_cmd(cmd, envp, ms_data);
	}
}

void	ft_infile_arg(char *gnl, t_ms_data *ms_data)
{
	pid_t	pid_pr;
	int		status;

	pid_pr = fork();
	if (pid_pr == -1)
	{
		perror("Error cmd_fork process");
		ft_signal_cmd(1, ms_data);
	}
	else if (pid_pr > 0)
	{
		waitpid(pid_pr, &status, 0);
		if (WIFEXITED(status))
			ft_signal_cmd(WEXITSTATUS(status), ms_data);
	}
	else
	{
		dup2(ms_data->fd_in, 0);
		ft_ex_cmd(gnl, g_ms_data->envp, ms_data);
	}
	close (ms_data->fd_in);
}

void	ft_inoutfile_arg(char **split, t_ms_data *ms_data)
{
	pid_t	pid_pr;
	int		status;

	pid_pr = fork();
	if (pid_pr == -1)
	{
		perror("Error cmd_fork process");
		ft_signal_cmd(1, ms_data);
	}
	else if (pid_pr > 0)
	{
		waitpid(pid_pr, &status, 0);
		if (WIFEXITED(status))
			ft_signal_cmd(WEXITSTATUS(status), ms_data);
	}
	else
	{
		dup2(ms_data->fd_in, 0);
		dup2(ms_data->fd_blt, 1);
		ft_pipe2(split[0], g_ms_data->envp, ms_data->fd_in, ms_data);
		ft_ex_cmd(split[0], g_ms_data->envp, ms_data);
	}
	close (ms_data->fd_blt);
	close (ms_data->fd_in);
}
