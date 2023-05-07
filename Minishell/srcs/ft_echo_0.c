/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:06:11 by jaromero          #+#    #+#             */
/*   Updated: 2022/11/28 19:23:18 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo_option_n(char **split, char **envp, int fd)
{
	int	i;

	i = 1;
	(void)envp;
	if (!split[2])
		return ;
	while (ft_strncmp(split[i], "-n", 2) == 0)
		i++;
	while (split[i])
	{
		ft_putstr_fd(split[i], fd);
		if (split[i + 1])
			write(fd, " ", 1);
		i++;
	}
}

void	ft_echo_standard(char **split, char **envp, int fd)
{
	int	i;

	i = 0;
	(void)envp;
	while (split[++i])
	{
		ft_putstr_fd(split[i], fd);
		if (!split[i + 1])
			write(fd, "\n", 1);
		if (split[i + 1])
			write(fd, " ", 1);
	}
}

void	ft_echo(char **split, char **envp, t_ms_data *ms_data)
{
	if (split[1] == NULL)
		write(ms_data->fd_blt, "\n", 1);
	else if (ft_strncmp(split[1], "-n", 2) == 0)
		ft_echo_option_n(split, envp, ms_data->fd_blt);
	else if (ft_strncmp(split[1], "$?", 2) == 0)
	{
		ft_putstr_fd(ms_data->v_exit, ms_data->fd_blt);
		ft_putstr_fd("\n", ms_data->fd_blt);
	}
	else
		ft_echo_standard(split, envp, ms_data->fd_blt);
	ft_signal_cmd(0, ms_data);
}
