/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements_3_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 09:33:45 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/08 12:25:41 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_enemy_in_len(t_imgdata *game, int lines, char **map)
{
	int				y;
	unsigned long	x;

	y = 1;
	x = 1;
	game->len_enemy = malloc(sizeof(int) * 2);
	game->len_enemy[0] = 0;
	while (y < (lines - 2))
	{
		x = 1;
		while (x < (ft_strlen(map[y]) - 2))
		{
			if (map[y][x] == 'T')
				game->len_enemy[0] = game->len_enemy[0] + 1;
			x++;
		}
		y++;
	}
	game->e_x_axis = malloc((game->len_enemy[0] + 1) * sizeof(int));
	game->e_y_axis = malloc((game->len_enemy[0] + 1) * sizeof(int));
	game->enemy_state_up = malloc(sizeof(int) * (game->len_enemy[0] + 1));
	game->enemy_state_down = malloc(sizeof(int) * (game->len_enemy[0] + 1));
	game->enemy_state_left = malloc(sizeof(int) * (game->len_enemy[0] + 1));
	game->enemy_state_right = malloc(sizeof(int) * (game->len_enemy[0] + 1));
	game->enemy_loop = malloc(sizeof(int) * (game->len_enemy[0] + 1));
}

void	ft_load_enemy(t_imgdata *game)
{
	game->enemy_up = mlx_load_png("bonus/textures/enemy_up.png");
	game->enemy_down = mlx_load_png("bonus/textures/enemy_down.png");
	game->enemy_left = mlx_load_png("bonus/textures/enemy_left.png");
	game->enemy_right = mlx_load_png("bonus/textures/enemy_right.png");
	game->e_up = mlx_texture_to_image(game->mlx, game->enemy_up);
	game->e_down = mlx_texture_to_image(game->mlx, game->enemy_down);
	game->e_left = mlx_texture_to_image(game->mlx, game->enemy_left);
	game->e_right = mlx_texture_to_image(game->mlx, game->enemy_right);
}

void	ft_put_enemy(t_imgdata *game, int x, int y, char **map)
{
	if (map[y][x - 1] == '1' && map[y - 2][x - 1] == '1')
		game->enemy_xy[game->init_enemy] = 1;
	else
		game->enemy_xy[game->init_enemy] = 0;
	mlx_image_to_window(game->mlx, game->e_up, (x - 1) * 32, (y - 1) * 32);
	mlx_image_to_window(game->mlx, game->e_down, (x - 1) * 32, (y - 1) * 32);
	mlx_image_to_window(game->mlx, game->e_left, (x - 1) * 32, (y - 1) * 32);
	mlx_image_to_window(game->mlx, game->e_right, (x - 1) * 32, (y - 1) * 32);
	game->enemy_state_up[game->init_enemy] = 1;
	game->enemy_state_down[game->init_enemy] = 0;
	game->enemy_state_left[game->init_enemy] = 0;
	game->enemy_state_right[game->init_enemy] = 0;
	game->e_y_axis[game->init_enemy] = (y - 1) * 32;
	game->e_x_axis[game->init_enemy] = (x - 1) * 32;
	game->e_down->instances[game->init_enemy].z -= 1500;
	game->e_left->instances[game->init_enemy].z -= 1600;
	game->e_right->instances[game->init_enemy].z -= 1700;
}

void	ft_init_enemy(t_imgdata *game, char **map)
{
	int	y;
	int	x;

	game->init_enemy = 0;
	y = -1;
	game->enemy_xy = malloc(sizeof(int) * (game->len_enemy[0] + 2));
	ft_load_enemy(game);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'T')
			{
				ft_put_enemy(game, (x + 1), (y + 1), map);
				game->init_enemy = game->init_enemy + 1;
			}
		}
	}
}
