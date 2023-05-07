/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:58:21 by bjimenez          #+#    #+#             */
/*   Updated: 2022/12/20 12:10:33 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_wldtype(int type, char *wld, char *d_name)
{
	if (type == 1 && ft_strncmp(ft_n_punt(d_name, ft_strlen(wld)),
			wld, ft_strlen(wld)) == 0 && *d_name != '.')
		return (1);
	else if (type == 2 && !ft_strncmp(wld, d_name, ft_strlen(wld)))
		return (1);
	else if (type == 3 && ft_checktype3(wld, d_name))
		return (1);
	else if (type == 4 && ft_checktype4(wld, d_name))
		return (1);
	return (0);
}

char	*ft_check_type(char *wld, char *gnl, int wld_mode, char *d_name)
{
	char	*temp_gnl;

	if ((ft_check_wldtype(wld_mode, wld, d_name) == 1
			&& *d_name != '.')
		|| (ft_check_wldtype(wld_mode, wld, d_name)
			== 1 && *wld == '.' && *d_name == '.'))
	{
		temp_gnl = ft_strjoin(gnl, d_name);
		free (gnl);
		gnl = ft_strjoin(temp_gnl, " ");
		free (temp_gnl);
	}
	return (gnl);
}

char	*ft_checkdir_andtype(DIR *d, char *wld, t_aux_check *check, int wld_mod)
{
	struct dirent	*dir;
	char			*aux_gnl;

	dir = readdir(d);
	if (!ft_strchr(wld, '*') && wld_mod == 0)
		check->temp_gnl = ft_wld_strjoin(check->temp_gnl, wld);
	else
	{
		aux_gnl = ft_strdup(check->temp_gnl);
		while (dir != NULL)
		{
			check->temp_gnl = ft_check_type(wld, check->temp_gnl, wld_mod,
					dir->d_name);
			dir = readdir(d);
		}
		if (!ft_strncmp(check->temp_gnl, aux_gnl, ft_strlen(check->temp_gnl)))
			check->temp_gnl = ft_wld_strjoin(check->temp_gnl,
					check->split_gnl[check->pos]);
		free (aux_gnl);
	}
	return (check->temp_gnl);
}

char	*ft_checkdir(char **wld, char *gnl, int *wld_mode, char **p)
{
	DIR				*d;
	t_aux_check		check;

	check.pos = 0;
	check.temp_gnl = ft_strdup("");
	check.split_gnl = ft_split(gnl, ' ');
	while (wld[check.pos] && check.pos < ft_array_size(p))
	{
		d = opendir(".");
		if (d)
		{
			check.temp_gnl = ft_checkdir_andtype(d, wld[check.pos], &check,
					wld_mode[check.pos]);
			closedir(d);
			check.temp_gnl = ft_wld_strjoin(check.temp_gnl, " ");
		}
		check.pos++;
	}
	free_split(check.split_gnl);
	return (free (gnl), check.temp_gnl);
}
