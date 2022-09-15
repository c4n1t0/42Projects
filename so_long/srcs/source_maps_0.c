/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_maps_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 00:54:29 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/02 12:46:35 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len_map(char **map, int lines)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (i < (lines - 2))
	{
		if (ft_strlen(map[i]) != len)
			return (ft_putstr_fd("Error\nInvalid length of map\n", 2), -1);
		i++;
	}
	if (ft_strlen(map[i]) != (len - 1) || (ft_strlen(map[i]) == (len - 1)
			&& ft_strchr(map[i], '\n') != NULL))
		return (ft_putstr_fd("Error\nInvalid length of map\n", 2), -1);
	return (0);
}

int	ft_wall_up(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] == '1')
		i++;
	if (map[0][i] != '\n')
		return (ft_putstr_fd("Error\nInvalid Wall UP of map\n", 2), -1);
	return (0);
}

int	ft_wall_down(char **map, int lines)
{
	int	i;

	i = 0;
	while (map[lines - 1][i] == '1')
		i++;
	if (map[lines - 1][i] != '\0')
		return (ft_putstr_fd("Error\nInvalid Wall DOWN of map\n", 2), -1);
	return (0);
}

int	ft_wall_detector(char **map, int lines)
{
	if (ft_wall_up(map) == -1 || ft_wall_down(map, (lines - 1)) == -1)
		return (-1);
	return (0);
}

int	ft_wall_left_right(char **map, int lines)
{
	int	i;

	i = 1;
	while (i < lines - 1)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 2] != '1')
			return (ft_putstr_fd("Error\nBad Wall!!\n", 2), -1);
		i++;
	}
	return (0);
}
