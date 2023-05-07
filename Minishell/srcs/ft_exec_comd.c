/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_comd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:06:58 by bjimenez          #+#    #+#             */
/*   Updated: 2022/12/27 19:23:04 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_get_path(t_get_path *get, t_ms_data *ms_data)
{
	get->i = 0;
	get->cmd_path = NULL;
	get->all_paths = NULL;
	ms_data->sys_path = 0;
	ms_data->no_sys_path = 0;
	while (g_ms_data->envp[get->i] && ft_strncmp("PATH=",
			g_ms_data->envp[get->i], 5) != 0 && g_ms_data->envp[get->i])
		get->i++;
}

char	*ft_get_path(char **envp, char *cmd, t_ms_data *ms_data)
{
	t_get_path	get;

	ft_init_get_path(&get, ms_data);
	if (envp[get.i])
	{
		get.all_paths = ft_split(envp[get.i] + 5, ':');
		get.cmd_path = ft_check_path(get.all_paths, cmd);
		if (ft_strncmp(envp[get.i], "PATH=", 5) == 0 && get.cmd_path != NULL)
			ms_data->sys_path = 1;
		if (ft_array_size(get.all_paths) == 0)
			ms_data->sys_path = 0;
		else
			ms_data->no_sys_path = 1;
	}
	if (!get.cmd_path)
	{
		get.i = 0;
		getcwd(ms_data->act_path, MAX_B);
		get.cmd_path = ft_only_check_path(ms_data->act_path, cmd);
		if (get.cmd_path)
			ms_data->sys_path = 2;
	}
	if (get.all_paths != NULL)
		free_split(get.all_paths);
	return (get.cmd_path);
}

int	ft_print_error_access(char *cmd, char *path, t_ms_data *ms_data)
{
	struct stat	buff;
	int			i;

	i = lstat(path, &buff);
	if ((!path && ms_data->sys_path == 0 && *cmd != '.'
			&& ms_data->no_sys_path == 1) || (path && ms_data->sys_path == 2
			&& *cmd != '.' && ms_data->no_sys_path == 1
			&& !S_ISDIR(buff.st_mode)) || (S_ISDIR(buff.st_mode) && (*cmd != '.'
				&& *cmd != '/' && ft_strchr(cmd, '/') == NULL)))
		ft_error_cmd(cmd);
	if (i == -1)
		ft_error_file(cmd);
	if (S_ISDIR(buff.st_mode))
		ft_error_directory(cmd);
	if ((access(path, R_OK) == -1 && (*cmd == '.' || *cmd == '/'))
		|| (access(path, X_OK) == -1 && (*cmd == '.' || *cmd == '/')))
	{
		if (ms_data->sys_path == 0)
			ft_error_permission(path);
		else
			ft_error_permission(cmd);
	}
	if (open(path, O_RDONLY) == -1 && open(path, O_WRONLY) == -1)
		ft_error_permission(path);
	return (i);
}

void	ft_ex_cmd(char *cmd, char **envp, t_ms_data *ms_data)
{
	char	**args;
	char	*path;

	(void)ms_data;
	args = ft_split_pipe(cmd, ' ');
	args = ft_parse_quote(args);
	if (ft_strchr_int(args[0], '/') > -1 && *args[0] == '/')
	{
		ms_data->sys_path = 1;
		path = args[0];
	}
	else
		path = ft_get_path(envp, args[0], ms_data);
	ft_print_error_access(args[0], path, ms_data);
	execve(path, args, envp);
	free(path);
	ft_free_double_p(args);
	exit(0);
}
