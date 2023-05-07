/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:30:38 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/19 00:03:03 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Loop checking floor & roof
*/

int	cub_loop_check_floor_roof(char	*str)
{
	int	status;
	int	i;

	i = 0;
	status = 0;
	while (str[i] != '\0' && status == 0)
	{
		if ((str[i] < '0' && str[i] != ',') || str[i] > '9')
			status = 1;
		else
			i++;
	}
	return (status);
}

/*
**  Check roof and floor colour
*/

int	cub_check_floor_roof(t_map *map)
{
	int	status[2];

	status[0] = 0;
	status[1] = 0;
	if (cub_loop_check_floor_roof(map->c_floor) == 1
		|| cub_check_color(map->c_floor) == 1)
	{
		status[0] = 1;
		ft_putstr_fd("Error\nInvalid code of colour floor!\n", 2);
	}
	if (cub_loop_check_floor_roof(map->c_roof) == 1
		|| cub_check_color(map->c_roof) == 1)
	{
		status[1] = 1;
		ft_putstr_fd("Error\nInvalid code of colour roof!\n", 2);
	}
	if (status[0] == 1 || status[1] == 1)
		return (1);
	return (0);
}

/*
**	Check textures
*/

int	cub_check_data(t_map *map)
{
	if (!map->t_no || !map->t_so || !map->t_we || !map->t_ea || !map->c_floor
		|| !map->c_roof)
		return (ft_putstr_fd("Error\nTexture or colour no detected!\n", 2), 1);
	if (cub_check_texture_file(map) == 1 || cub_check_floor_roof(map) == 1)
		return (1);
	return (0);
}

/*
**  Save map data
*/

int	cub_save_data(t_map *map)
{
	char	*str;

	str = " ";
	while (str)
	{
		str = get_next_line(map->fd);
		if (str)
		{
			if (map->t_no == NULL || map->t_so == NULL || map->t_we == NULL
				|| map->t_ea == NULL || map->c_floor == NULL
				|| map->c_roof == NULL)
			{
				if (cub_save_texture(map, str) == 1)
					return (free(str), 1);
			}
			else
				if (cub_save_map(map, str) == 1)
					return (free(str), 1);
		}
		free(str);
	}
	if (cub_check_data(map) == 1)
		return (1);
	map->map = ft_split_remake(map->t_map, '\n');
	return (0);
}

/*
**  Check map and save data
*/

int	cub_check_map(t_map *map, char *file)
{
	if (cub_init_map_var(map, file) == 1 || cub_save_data(map) == 1)
		return (1);
	if (cub_read_map(map) == 1)
		return (1);
	return (0);
}
