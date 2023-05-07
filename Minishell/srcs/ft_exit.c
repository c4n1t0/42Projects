/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:06:33 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/27 19:30:23 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_force_exit(char *str, char **split)
{
	ft_printf("minishell: exit: %s: numeric argument required\n", str);
	free_split(split);
	exit(255);
}

void	ft_max_llong(char *str, char **split)
{
	if (*str == '-' && ft_strlen(str) >= 11)
	{
		if (ft_strncmp("-9223372036854775808", str, ft_strlen(str)) < 0)
			ft_force_exit(str, split);
	}
	if ((*str == '+' || ft_isdigit(*str) != 0) && ft_strlen(str) >= 10)
	{
		if (ft_strlen(str) > 20 || (ft_strlen(str) == 20 && *str != '+'))
			ft_force_exit(str, split);
		if (*str == '+' && ft_strlen(str) >= 10)
		{
			if (ft_strncmp("+9223372036854775807", str, ft_strlen(str)) < 0)
				ft_force_exit(str, split);
		}
		else if (ft_strncmp("9223372036854775807", str, ft_strlen(str)) < 0)
			ft_force_exit(str, split);
	}
}

void	ft_analytics_exit(char *str, char **split)
{
	char	*p;

	p = str;
	if (*p == '-' || *p == '+')
	{
		p++;
		if (ft_isdigit(*p) == 0)
			ft_force_exit(str, split);
	}
	if (ft_isdigit(*p) == 0)
		ft_force_exit(str, split);
	while (*p != '\0')
	{
		if (ft_isdigit(*p) == 0 && (*p != ' ' && *p != '\t'))
			ft_force_exit(str, split);
		p++;
	}
	if (*p == '\0')
		ft_max_llong(str, split);
}

long long int	ft_delete_cero(char *str, char **split)
{
	char			*p;
	long long int	nbr;

	str = ft_delete_isspaces(str);
	p = str;
	if (ft_strlen(p) < 21)
		ft_analytics_exit(p, split);
	while (*p == '0' && *p != '\0')
		p++;
	if (*p == '\0')
		return (0);
	ft_analytics_exit(p, split);
	nbr = ft_atoi(str);
	if (nbr > 255)
		return (nbr % 256);
	return (nbr);
}

void	ft_exit(char **split, t_ms_data *ms_data)
{
	char	*str;

	ft_printf("exit\n");
	if (ft_array_size(split) == 1)
	{
		free_split(split);
		exit(0);
	}
	if (ft_array_size(split) > 1)
		ft_delete_cero(split[1], split);
	if (ft_array_size(split) > 2)
	{
		ft_printf("minishell: exit: too many arguments\n");
		ft_signal_cmd(1, ms_data);
		return ;
	}
	str = malloc(sizeof(char) * (ft_strlen(split[1]) + 1));
	if (!str)
		return ;
	if (ft_array_size(split) > 1)
	{
		ft_strlcpy(str, split[1], (ft_strlen(split[1]) + 1));
		free_split(split);
		exit(ft_delete_cero(str, split));
	}
}
