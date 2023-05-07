/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:56:22 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/27 16:40:37 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_print_error(char **split, int i)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(split[i], 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

char	*ft_export_sub_print_envp(char *p, int fd)
{
	while (*p != '=' && *p != '\0')
	{
		write(fd, p, 1);
		p++;
	}
	return (p);
}

void	ft_export_print_envp(t_ms_data *ms_data)
{
	int		i;
	char	c;
	char	*p;

	c = 34;
	i = -1;
	while (g_ms_data->envp[++i])
	{
		ft_putstr_fd("declare -x ", ms_data->fd_blt);
		p = g_ms_data->envp[i];
		p = ft_export_sub_print_envp(p, ms_data->fd_blt);
		write(ms_data->fd_blt, p, 1);
		p++;
		write(ms_data->fd_blt, &c, 1);
		p = ft_export_sub_print_envp(p, ms_data->fd_blt);
		write(ms_data->fd_blt, &c, 1);
		write(ms_data->fd_blt, "\n", 1);
	}
}

int	ft_validation_var(char *str)
{
	char	*p;
	char	*q;

	p = str;
	if (ft_isalpha(*p) == 0 && *p != '_')
		return (1);
	q = ft_strchr(str, '=');
	if (p == q)
		return (1);
	while (p != q && *p != '\0')
	{
		if (ft_isalnum(*p) == 0 && *p != '_')
			return (1);
		p++;
	}
	return (0);
}
