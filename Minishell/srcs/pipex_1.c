/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:25:09 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/17 20:57:46 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipes(char **split, char **envp, t_ms_data *ms_data)
{
	int		size;
	int		fd_pipe[2];
	int		status;

	size = ft_array_size(split);
	pipe(fd_pipe);
	ms_data->pid_pr = fork();
	if (ms_data->pid_pr == -1)
	{
		ft_signal_cmd(1, ms_data);
		perror("minihsell: Error cmd_fork process");
	}
	else if (ms_data->pid_pr > 0)
	{
		waitpid(ms_data->pid_pr, &status, 0);
		if (WIFEXITED(status))
			ft_signal_cmd(WEXITSTATUS(status), ms_data);
	}
	else
		pipex(size, split, envp, ms_data);
}
