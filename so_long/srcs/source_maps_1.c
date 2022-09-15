/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_maps_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 08:41:13 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/02 12:50:06 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validator_empty_space(char **map, int lines)
{
	int	i;
	int	x;

	i = 0;
	while (i < lines)
	{
		x = 0;
		while (map[i][x] != '\n' && map[i][x] != '\0')
		{
			if (map[i][x] != '1' && map[i][x] != '0' && map[i][x] != 'C'
				&& map[i][x] != 'E' && map[i][x] != 'P')
				return (ft_putstr_fd("Error\nInvalid caracter on map!\n", 2), -1);
			x++;
		}
		i++;
	}
	return (0);
}

int	ft_initial_case_validator(char **map, int lines)
{
	struct s_map	data;

	data.i = 0;
	data.c = 0;
	data.e = 0;
	data.p = 0;
	while (data.i < lines)
	{
		data.x = 0;
		while (map[data.i][data.x] != '\n' && map[data.i][data.x] != '\0')
		{
			if (map[data.i][data.x] == 'C')
				data.c++;
			if (map[data.i][data.x] == 'E')
				data.e++;
			if (map[data.i][data.x] == 'P')
				data.p++;
			data.x++;
		}
		data.i++;
	}
	if (data.c < 1 || data.e < 1 || data.p != 1)
		return (ft_putstr_fd("Error\nInvalid case of map!!\n", 2), -1);
	return (0);
}

int	ft_source_validator_map(char **map, int lines)
{
	if (ft_len_map(map, lines) == -1 || ft_wall_detector(map, lines) == -1
		|| ft_wall_left_right(map, (lines - 1)) == -1
		|| ft_validator_empty_space(map, (lines - 1)) == -1
		|| ft_initial_case_validator(map, (lines - 1)) == -1)
		return (-1);
	return (0);
}
