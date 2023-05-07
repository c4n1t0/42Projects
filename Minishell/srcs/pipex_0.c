/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:49:19 by bjimenez          #+#    #+#             */
/*   Updated: 2022/12/27 17:37:05 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_p_ex_cmd(char *cmd, char **envp, t_ms_data *ms_data)
{
	char	**args;
	char	*path;

	cmd = ft_strtrim(cmd, " ");
	cmd = ft_redirections_prepare(cmd, ms_data);
	if (ft_check_gnl(cmd) == 0)
		return (free (cmd), exit (0));
	args = ft_split_pipe(cmd, ' ');
	args = ft_parse_quote(args);
	if (ft_builtins(args, ms_data) == 1)
		exit (0);
	if (ms_data->redirection_status != 0)
	{
		ft_redirecions_exec(ms_data, args, cmd);
		exit (0);
	}
	if (ft_strchr_int(args[0], '/') > -1)
		path = args[0];
	else
		path = ft_get_path(envp, args[0], ms_data);
	ft_print_error_access(args[0], path, ms_data);
	execve(path, args, envp);
	free(path);
	exit (0);
}

void	ft_pipe_closedup(int fd_close, int fd_dup, int v_dup)
{
	close(fd_close);
	dup2(fd_dup, v_dup);
}

void	ft_pipe(char *cmd, char **envp, int fd, t_ms_data *ms_data)
{
	pid_t	pid;
	int		fd_pipe[2];
	int		status;

	pipe(fd_pipe);
	pid = fork();
	if (pid == -1)
		ft_error_fork(ms_data);
	else if (pid > 0)
	{
		ft_pipe_closedup(fd_pipe[1], fd_pipe[0], 0);
		waitpid(pid, &status, WUNTRACED | WNOHANG);
	}
	else
	{
		ft_pipe_closedup(fd_pipe[0], fd_pipe[1], 1);
		if (fd == 0)
		{
			ft_signal_cmd(1, ms_data);
			exit(1);
		}
		else
			ft_p_ex_cmd(cmd, envp, ms_data);
	}
	ms_data->pid_pr = 0;
}

int	pipex(int argc, char **argv, char **envp, t_ms_data *ms_data)
{
	int			i;
	int			fd;

	i = 1;
	fd = 1;
	dup2(fd, 0);
	ft_pipe(argv[0], envp, fd, ms_data);
	while (i < argc - 1)
		ft_pipe(argv[i++], envp, fd, ms_data);
	ft_delay_exec();
	ft_p_ex_cmd(argv[i], envp, ms_data);
	return (0);
}
