/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:09:36 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/23 10:50:49 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
**	Check if gnl is a map line
*/

int	cub_check_line_map(t_map *map, char *gnl)
{
	char	*p;
	int		detect;

	detect = 0;
	p = gnl;
	while (*p != '\0')
	{
		if (*p == 'N' || *p == 'S' || *p == 'W' || *p == 'E')
		{
			map->pos_player++;
			if (map->count == 0)
				return (1);
		}
		if (*p != ' ' && *p != '1' && *p != '0' && *p != '\n' && *p != 'N'
			&& *p != 'S' && *p != 'E' && *p != 'W' && *p != 'D' && *p != 'U')
			return (1);
		if (*p == '1' || *p == '0' || *p == ' ')
			detect = 1;
		p++;
	}
	if (detect == 0)
		return (1);
	return (0);
}

/*
** Save map, return 1 on error
*/

int	cub_save_map(t_map *map, char *gnl)
{
	if (*gnl == '\n')
	{
		free(gnl);
		gnl = ft_strdup(" \n");
	}
	if (cub_check_line_map(map, gnl) == 0)
	{
		if (map->count == 0)
			map->t_map = ft_strdup(gnl);
		else
			map->t_map = ft_free_and_save(map->t_map, gnl);
		map->count++;
		return (0);
	}
	if (map->count == 0)
		if (cub_check_data_file(gnl) == 1)
			return (1);
	if (map->count == 0)
		return (0);
	return (ft_putstr_fd("Error\nInvalid character on map!\n", 2), 1);
}

/*
**	Convert colors from file map
*/

void	ft_set_color(t_cub *cub)
{
	char		**color_string;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	color_string = ft_split(cub->s_map->c_floor, ',');
	r = ft_atoi(color_string[0]) & 0xFF;
	g = (ft_atoi(color_string[1])) & 0xFF;
	b = (ft_atoi(color_string[2])) & 0xFF;
	cub->s_map->color_floor = ((r << 24) | (g << 16) | (b << 8) | 255);
	free_double_p(color_string);
	color_string = ft_split(cub->s_map->c_roof, ',');
	r = ft_atoi(color_string[0]) & 0xFF;
	g = (ft_atoi(color_string[1]) & 0xFF);
	b = (ft_atoi(color_string[2]) & 0xFF);
	cub->s_map->color_roof = ((r << 24) | (g << 16) | (b << 8) | 255);
	free_double_p(color_string);
}

/*
**  Init values of map struct
*/

int	cub_init_map_var(t_map *map, char *file)
{
	map->c_floor = NULL;
	map->c_roof = NULL;
	map->t_ea = NULL;
	map->t_we = NULL;
	map->t_so = NULL;
	map->t_no = NULL;
	map->t_door = NULL;
	map->t_spr = NULL;
	map->map = NULL;
	map->pos_player = 0;
	map->t_map = NULL;
	map->count = 0;
	map->len_line = 0;
	if (ft_strncmp((file + (ft_strlen(file) - 4)), ".cub", 3) != 0)
		return (ft_putstr_fd("Error\nInvalid extension map!\n", 2), 1);
	map->fd = open(file, O_RDONLY);
	if (map->fd < 0)
		return (ft_putstr_fd("Error\nCan´t open file map!\n", 2), 1);
	else
		return (0);
}

/*
**	Check map is closed
*/

int	cub_read_map(t_map *map)
{
	cub_big_str_map(map);
	cub_equal_line(map);
	if (cub_first_last_line(map->map) == 1)
		return (ft_putstr_fd("Error\nMap is open!!\n", 2), 1);
	if (cub_rest_lines(map->map) == 1)
		return (1);
	if (map->pos_player == 0)
		return (ft_putstr_fd("Error\nNo detection init player position!\n",
				2), 1);
	if (map->pos_player != 1)
		return (ft_putstr_fd("Error\nToo many init player position!\n", 2), 1);
	return (0);
}
