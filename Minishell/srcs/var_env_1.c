/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 00:13:13 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/26 12:00:27 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_change_lvl(char *str)
{
	char	*p;
	char	*temp;
	int		lvl;

	p = ft_strchr(str, '=');
	if (!p)
		return (str);
	p++;
	lvl = ft_atoi(p);
	if (lvl > 1000)
	{
		lvl++;
		ft_putstr_fd("minishell: warning: shell level (", 2);
		ft_putstr_fd(ft_itoa(lvl), 2);
		ft_putstr_fd(") too high, resetting to 1\n", 2);
		lvl = 0;
	}
	if (lvl < 0)
		lvl = 0;
	else
		lvl++;
	p = ft_itoa(lvl);
	temp = ft_strjoin("SHLVL=", p);
	free(p);
	return (temp);
}

void	ft_save_envp_global(char **envpi)
{
	t_sv_envp	sv;

	sv.shlvl = 0;
	sv.i = -1;
	sv.x = 0;
	g_ms_data->envp = malloc(sizeof(char *) * (ft_array_size(envpi) + 1));
	if (!g_ms_data->envp)
		return ;
	while (envpi[++sv.i])
	{
		if (ft_strnstr(envpi[sv.i], "OLDPWD=", 7) != NULL)
			sv.i++;
		if (ft_strnstr(envpi[sv.i], "SHLVL=", 6) != NULL)
		{
			g_ms_data->envp[sv.x] = ft_change_lvl(envpi[sv.i]);
			sv.shlvl = 1;
		}
		else
			g_ms_data->envp[sv.x] = ft_strdup(envpi[sv.i]);
		sv.x++;
	}
	g_ms_data->envp[sv.x] = NULL;
	if (sv.shlvl == 0)
		ft_export_exec("SHLVL=1");
}

void	ft_change_last_exec(char *str, t_ms_data *ms_data, int pipe)
{
	char	*p;
	char	*q;

	if (pipe == 1)
		ft_export_exec("_=");
	else
	{
		q = ft_get_path(g_ms_data->envp, str, ms_data);
		if (!q)
		{
			q = ft_strjoin("_=", str);
			ft_export_exec(q);
			return (free (q));
		}
		p = ft_strjoin("_=", q);
		free (q);
		ft_export_exec(p);
		free(p);
	}
}
