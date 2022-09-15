/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:14:12 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/04 08:32:34 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **p)
{
	int	x;

	x = -1;
	while (p[++x])
		free(p[x]);
	free(p);
}

void	ft_open_door(t_imgdata *data2)
{
	int	i;

	i = 0;
	if (data2->door_state == 0)
	{
		while (i < data2->len_exit)
		{
			data2->i_exit->instances[i].z -= 1000;
			data2->i_exit1->instances[i].z += 1000;
			i++;
		}
		data2->door_state = 1;
	}
}

int	ft_check_col(t_imgdata *data2)
{
	int	i;

	i = 0;
	while (i < data2->len_collect)
	{
		if (data2->col_state[i] == 0)
			return (-1);
		i++;
	}
	return (0);
}

void	ft_init_col_state(t_imgdata *game)
{
	int	i;

	i = 0;
	while (i < game->len_collect)
	{
		game->col_state[i] = 0;
		i++;
	}
}

void	ft_size_windows(t_imgdata *game, char **map)
{
	int			i;

	i = 0;
	game->door_state = 0;
	game->counter = 0;
	game->width = (ft_strlen(map[0]) - 1) * 32;
	while (map[i])
		i++;
	game->height = i * 32;
}
