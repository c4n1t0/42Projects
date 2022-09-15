/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:12:04 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/12 11:43:24 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_init_sprite(t_imgdata *game)
{
	game->collect_0 = mlx_load_png("bonus/textures/Gold_21.png");
	game->collect_1 = mlx_load_png("bonus/textures/Gold_22.png");
	game->collect_2 = mlx_load_png("bonus/textures/Gold_23.png");
	game->collect_3 = mlx_load_png("bonus/textures/Gold_24.png");
	game->collect_4 = mlx_load_png("bonus/textures/Gold_25.png");
	game->collect_5 = mlx_load_png("bonus/textures/Gold_26.png");
	game->collect_6 = mlx_load_png("bonus/textures/Gold_27.png");
	game->collect_7 = mlx_load_png("bonus/textures/Gold_28.png");
	game->collect_8 = mlx_load_png("bonus/textures/Gold_29.png");
	game->collect_9 = mlx_load_png("bonus/textures/Gold_30.png");
	game->i_collect_0 = mlx_texture_to_image(game->mlx, game->collect_0);
	game->i_collect_1 = mlx_texture_to_image(game->mlx, game->collect_1);
	game->i_collect_2 = mlx_texture_to_image(game->mlx, game->collect_2);
	game->i_collect_3 = mlx_texture_to_image(game->mlx, game->collect_3);
	game->i_collect_4 = mlx_texture_to_image(game->mlx, game->collect_4);
	game->i_collect_5 = mlx_texture_to_image(game->mlx, game->collect_5);
	game->i_collect_6 = mlx_texture_to_image(game->mlx, game->collect_6);
	game->i_collect_7 = mlx_texture_to_image(game->mlx, game->collect_7);
	game->i_collect_8 = mlx_texture_to_image(game->mlx, game->collect_8);
	game->i_collect_9 = mlx_texture_to_image(game->mlx, game->collect_9);
}

void	ft_sprite_to_windows(t_imgdata *game, int i, int x, int y)
{
	mlx_image_to_window(game->mlx, game->i_collect_0, x * 32, y * 32);
	mlx_image_to_window(game->mlx, game->i_collect_1, x * 32, y * 32);
	mlx_image_to_window(game->mlx, game->i_collect_2, x * 32, y * 32);
	mlx_image_to_window(game->mlx, game->i_collect_3, x * 32, y * 32);
	mlx_image_to_window(game->mlx, game->i_collect_4, x * 32, y * 32);
	mlx_image_to_window(game->mlx, game->i_collect_5, x * 32, y * 32);
	mlx_image_to_window(game->mlx, game->i_collect_6, x * 32, y * 32);
	mlx_image_to_window(game->mlx, game->i_collect_7, x * 32, y * 32);
	mlx_image_to_window(game->mlx, game->i_collect_8, x * 32, y * 32);
	mlx_image_to_window(game->mlx, game->i_collect_9, x * 32, y * 32);
	mlx_set_instance_depth(&game->i_collect_1->instances[i], -2100);
	mlx_set_instance_depth(&game->i_collect_2->instances[i], -2200);
	mlx_set_instance_depth(&game->i_collect_3->instances[i], -2300);
	mlx_set_instance_depth(&game->i_collect_4->instances[i], -2400);
	mlx_set_instance_depth(&game->i_collect_5->instances[i], -2500);
	mlx_set_instance_depth(&game->i_collect_6->instances[i], -2600);
	mlx_set_instance_depth(&game->i_collect_7->instances[i], -2700);
	mlx_set_instance_depth(&game->i_collect_8->instances[i], -2800);
	mlx_set_instance_depth(&game->i_collect_9->instances[i], -2900);
}

void	ft_init_collect(t_imgdata *game, char **map)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	y = -1;
	ft_init_sprite(game);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
			{
				ft_sprite_to_windows(game, i, x, y);
				i++;
			}
		}
	}
}
