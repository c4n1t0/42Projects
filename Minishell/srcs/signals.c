/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:40:12 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/27 13:45:46 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_act_signals(int signal)
{
	(void) signal;
	ft_signal_cmd(1, g_ms_data);
	g_ms_data->status_sig = 1;
	if (g_ms_data->pid_pr != 0)
	{
		kill(g_ms_data->pid_pr, SIGTERM);
		g_ms_data->pid_pr = 0;
		write(1, "\n", 1);
		return ;
	}
	rl_on_new_line();
	rl_redisplay();
	rl_replace_line("", 0);
	write(1, "  \n", 3);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_signal_cmd(int exit, t_ms_data *ms_data)
{
	free (ms_data->v_exit);
	ms_data->v_exit = ft_itoa(exit);
}
