/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:05:51 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/27 16:34:46 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_free_and_save(char *str, char *envp)
{
	char	*temp;

	temp = ft_strdup(str);
	free(envp);
	return (temp);
}

char	**ft_sub_export_exec(char *str)
{
	char	**aux;
	int		i;

	aux = malloc(sizeof(char *) * (ft_array_size(g_ms_data->envp) + 2));
	if (!aux)
		return (NULL);
	i = 0;
	while (g_ms_data->envp[i])
	{
		aux[i] = ft_strdup(g_ms_data->envp[i]);
		i++;
	}
	aux[i] = ft_strdup(str);
	aux[++i] = NULL;
	free_split(g_ms_data->envp);
	return (aux);
}

void	ft_export_exec(char *str)
{
	int		i;
	char	*q;
	char	*p;

	p = ft_strdup(str);
	q = ft_strchr(p, '=');
	q++;
	*q = '\0';
	i = 0;
	while (g_ms_data->envp[i] != NULL)
	{
		if (ft_strnstr(g_ms_data->envp[i], p, (ft_strlen(g_ms_data->envp[i])
					+ 1)) != NULL && *p == *str)
		{
			if (ft_strlen(str) != ft_strlen(g_ms_data->envp[i]))
				g_ms_data->envp[i] = ft_free_and_save(str, g_ms_data->envp[i]);
			else
				ft_strlcpy(g_ms_data->envp[i], str,
					(ft_strlen(g_ms_data->envp[i]) + 1));
			return (free(p));
		}
		i++;
	}
	g_ms_data->envp = ft_sub_export_exec(str);
	return (free(p));
}

int	ft_export_source(char **split, int i, t_ms_data *ms_data)
{
	if (ft_validation_var(split[i]) == 1)
	{
		ft_signal_cmd(1, ms_data);
		return (ft_export_print_error(split, i), 1);
	}
	if (ft_strchr(split[i], '=') == 0 && split[i + 1])
	{
		ft_signal_cmd(1, ms_data);
		return (ft_export_print_error(split, i), 1);
	}
	if (ft_strchr(split[i], '=') == 0)
		return (1);
	return (0);
}

void	ft_export(char **split, t_ms_data *ms_data)
{
	int	i;

	i = 1;
	if (ft_array_size(split) < 2)
	{
		ft_signal_cmd(0, ms_data);
		ft_export_print_envp(ms_data);
		return ;
	}
	while (split[i])
	{
		if (ft_export_source(split, i, ms_data) == 0)
			ft_export_exec(split[i]);
		i++;
	}
}
