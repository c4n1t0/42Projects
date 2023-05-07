/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_rest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:03:39 by bjimenez          #+#    #+#             */
/*   Updated: 2022/12/15 18:35:31 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exc_rest(char *gnl, char **envp, t_ms_data *ms_data)
{
	int		status;

	ms_data->pid_pr = fork();
	if (ms_data->pid_pr == -1)
	{
		ft_signal_cmd(1, ms_data);
		perror("minishell: Error cmd_fork process");
	}
	else if (ms_data->pid_pr > 0)
	{
		waitpid(ms_data->pid_pr, &status, 0);
		if (WIFEXITED(status))
			ft_signal_cmd(WEXITSTATUS(status), ms_data);
	}
	else
	{
		ft_ex_cmd(gnl, envp, ms_data);
		exit(127);
	}
	ms_data->pid_pr = 0;
}
