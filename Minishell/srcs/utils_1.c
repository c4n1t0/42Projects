/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:16:41 by bjimenez          #+#    #+#             */
/*   Updated: 2022/11/30 12:51:30 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_array_size(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		i++;
	return (i);
}

void	ft_free_double_p(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	ft_strchr_int(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*ft_check_path(char **all_paths, char *cmd)
{
	int		i;
	char	*path;
	char	*cmd_path;

	i = -1;
	while (all_paths[++i])
	{
		path = ft_strjoin(all_paths[i], "/");
		cmd_path = ft_strjoin(path, cmd);
		free(path);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (NULL);
}

char	*ft_only_check_path(char *all_paths, char *cmd)
{
	char	*path;
	char	*cmd_path;

	path = ft_strjoin(all_paths, "/");
	cmd_path = ft_strjoin(path, cmd);
	free(path);
	if (access(cmd_path, F_OK) == 0)
		return (cmd_path);
	free(cmd_path);
	return (NULL);
}
