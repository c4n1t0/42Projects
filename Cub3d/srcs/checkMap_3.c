/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:40:53 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/18 11:42:43 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Search biggest line of map
*/

void	cub_big_str_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) > (size_t)map->len_line)
			map->len_line = ft_strlen(map->map[i]);
		i++;
	}
}

/*
**	Equal all lines
*/

void	cub_equal_line(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) < (size_t)map->len_line)
		{
			while (ft_strlen(map->map[i]) < (size_t)map->len_line)
			{
				map->map[i] = ft_free_and_save(map->map[i], " ");
			}
		}
		i++;
	}
}

/*
**	First and last map's line validation
*/

int	cub_first_last_line(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_len_double_pointer(map);
	while (map[0][i] != '\0')
	{
		if (map[0][i] != ' ' && map[0][i] != '1')
			return (1);
		if (map[len - 1][i] != ' ' && map[len - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

/*
**	Rest of lines validation sub-loop
*/

int	cub_sub_rest_lines(char **map, int i, int x)
{
	if ((map[i - 1][x] == '0' || map[i - 1][x] == '1' || map[i - 1][x] == 'N'
		|| map[i - 1][x] == 'S' || map[i - 1][x] == 'E' || map[i - 1][x] == 'W')
		&& (map[i + 1][x] == '0' || map[i + 1][x] == '1' || map[i + 1][x] == 'N'
		|| map[i + 1][x] == 'S' || map[i + 1][x] == 'E' || map[i + 1][x] == 'W')
		&& (map[i][x + 1] == '0' || map[i][x + 1] == '1' || map[i][x + 1] == 'N'
		|| map[i][x + 1] == 'S' || map[i][x + 1] == 'E' || map[i][x + 1] == 'W')
		&& (map[i][x - 1] == '0' || map[i][x - 1] == '1' || map[i][x - 1] == 'N'
		|| map[i][x - 1] == 'S' || map[i][x - 1] == 'E'
		|| map[i][x - 1] == 'W'))
		return (0);
	else
		return (1);
}

/*
**	Rest of map's lines validation
*/

int	cub_rest_lines(char **map)
{
	int	i;
	int	x;
	int	len;

	i = 1;
	len = ft_len_double_pointer(map) - 2;
	while (i <= len)
	{
		x = 0;
		while (map[i][x] != '\0')
		{
			if (map[i][x] == '0' || map[i][x] == 'N' || map[i][x] == 'S'
				|| map[i][x] == 'E' || map[i][x] == 'W')
			{
				if (cub_sub_rest_lines(map, i, x) == 0)
					x++;
				else
					return (1);
			}
			else
				x++;
		}
		i++;
	}
	return (0);
}
