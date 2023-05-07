/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:17:09 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/17 21:42:57 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_split(char **p)
{
	int	x;

	x = -1;
	while (p[++x])
		free(p[x]);
	free(p);
}

void	ft_putstr_mod(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0' && s[i] != '\n')
	{
		write(fd, s + i, 1);
		i++;
	}
}

void	ft_print_env(char **envp, t_ms_data *ms_data)
{
	int	i;

	i = 0;
	(void)envp;
	while (g_ms_data->envp[i])
	{
		ft_putstr_fd(g_ms_data->envp[i], ms_data->fd_blt);
		ft_putstr_fd("\n", ms_data->fd_blt);
		i++;
	}
	ft_signal_cmd(0, ms_data);
}

char	*ft_delete_spaces(char *gnl)
{
	char	*p;
	int		i;

	i = -1;
	p = gnl;
	while (*p == '	' || *p == ' ' || *p == '\n')
		p++;
	while (*p != '\0')
	{
		gnl[++i] = *p;
		p++;
	}
	gnl[++i] = '\0';
	return (gnl);
}
