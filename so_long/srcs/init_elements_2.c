/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:12:04 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/04 08:42:38 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_collect(t_imgdata *game, char **map)
{
	int	y;
	int	x;

	y = -1;
	game->collect = mlx_load_png("srcs/textures/trofeo.png");
	game->i_collect = mlx_texture_to_image(game->mlx, game->collect);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->i_collect, x * 32, y * 32);
	}
}

void	ft_collect_in_len(t_imgdata *game, int lines, char **map)
{
	int				y;
	unsigned long	x;

	y = 1;
	x = 1;
	game->len_collect = 0;
	game->game_collect = 0;
	while (y < (lines - 2))
	{
		x = 1;
		while (x < (ft_strlen(map[y]) - 2))
		{
			if (map[y][x] == 'C')
				game->len_collect = game->len_collect + 1;
			x++;
		}
		y++;
	}
	game->col_x = malloc((game->len_collect + 1) * sizeof(int));
	game->col_y = malloc((game->len_collect + 1) * sizeof(int));
	game ->col_state = malloc((game->len_collect + 1) * sizeof(int));
}

void	ft_collect_in_block(t_imgdata *game, int lines, char **map)
{
	int				y;
	unsigned long	x;
	int				i;

	i = 0;
	y = 1;
	x = 1;
	while (y < (lines - 2))
	{
		x = 1;
		while (x < (ft_strlen(map[y]) - 2))
		{
			if (map[y][x] == 'C')
			{
				game->col_x[i] = x * 32 + 8;
				game->col_y[i] = y * 32 + 8;
				i++;
			}
			x++;
		}
		y++;
	}
}
