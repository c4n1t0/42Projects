/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:28:26 by bjimenez          #+#    #+#             */
/*   Updated: 2022/12/19 11:00:23 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_ms_data *ms_data)
{
	if (getcwd(ms_data->act_path, MAX_B) == NULL)
	{
		printf("Unable to read directory. Length exceeds buffer size\n");
		ft_signal_cmd(1, ms_data);
	}
	else
	{
		ft_putstr_fd(ms_data->act_path, ms_data->fd_blt);
		write(ms_data->fd_blt, "\n", 1);
		ft_signal_cmd(0, ms_data);
	}
}

void	ft_act_folder(t_ms_data *ms_data)
{
	char	**path_list;
	char	*p;
	int		i;

	i = 0;
	getcwd(ms_data->act_path, MAX_B);
	path_list = ft_split(ms_data->act_path, '/');
	while (path_list[i] != 0)
		i++;
	free (ms_data->act_folder);
	ms_data->act_folder = ft_strdup(path_list[i - 1]);
	p = ft_strjoin("PWD=", ms_data->act_path);
	ft_export_exec(p);
	free(p);
	free_split(path_list);
}

char	*ft_home(void)
{
	char	*p;
	int		i;

	i = 0;
	while (g_ms_data->envp[i])
	{
		if (ft_strncmp(g_ms_data->envp[i], "HOME=", 5) == 0)
		{
			p = g_ms_data->envp[i];
			while (*p != '=' && *p != '\0')
				p++;
			if (p)
				p++;
			return (p);
		}
		i++;
	}
	return (0);
}

void	ft_oldpwd(t_ms_data *ms_data)
{
	char	*p;

	getcwd(ms_data->act_path, MAX_B);
	p = ft_strjoin("OLDPWD=", ms_data->act_path);
	ft_export_exec(p);
	free(p);
}

void	ft_cd(t_ms_data *ms_data, char *new_path)
{
	char	*p;

	ft_oldpwd(ms_data);
	if (new_path == NULL)
	{
		new_path = ft_home();
		p = ft_strjoin("PWD=", new_path);
		ft_export_exec(p);
		free(p);
		chdir(new_path);
		ft_signal_cmd(0, ms_data);
	}
	else if (chdir(new_path) == -1)
	{
		printf("minishell: cd: %s no such file or directory\n", new_path);
		ft_signal_cmd(1, ms_data);
	}
	else
	{
		ft_act_folder(ms_data);
		ft_signal_cmd(0, ms_data);
	}
}
