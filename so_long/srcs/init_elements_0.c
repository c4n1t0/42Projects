/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:57:05 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/03 20:12:49 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_wall_in_len(t_imgdata *game, int lines, char **map)
{
	int				y;
	unsigned long	x;

	y = 1;
	x = 1;
	game->len_obs = 0;
	while (y < (lines - 2))
	{
		x = 1;
		while (x < (ft_strlen(map[y]) - 2))
		{
			if (map[y][x] == '1')
				game->len_obs = game->len_obs + 1;
			x++;
		}
		y++;
	}
	game->obs_x = malloc((game->len_obs + 1) * sizeof(int));
	game->obs_y = malloc((game->len_obs + 1) * sizeof(int));
}

void	ft_wall_in_block(t_imgdata *game, int lines, char **map)
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
			if (map[y][x] == '1')
			{
				game->obs_x[i] = x * 32;
				game->obs_y[i] = y * 32;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	ft_init_wall(t_imgdata *game, char **map)
{
	int	pixel_x;
	int	pixel_y;
	int	x;
	int	i;

	i = -1;
	pixel_y = 0;
	game->wall = mlx_load_png("srcs/textures/wall32.png");
	game->i_wall = mlx_texture_to_image(game->mlx, game->wall);
	while (map[++i])
	{
		x = -1;
		pixel_x = 0;
		while (map[i][++x])
		{
			if (map[i][x] == '1')
				mlx_image_to_window(game->mlx, game->i_wall, pixel_x, pixel_y);
			pixel_x = pixel_x + 32;
		}
		pixel_y = pixel_y + 32;
	}
}

void	ft_texture_player(t_imgdata *game, int x, int y)
{
	game->player = mlx_load_png("srcs/textures/player_right.png");
	game->player_left = mlx_load_png("srcs/textures/player_left.png");
	game->player_up = mlx_load_png("srcs/textures/player_up.png");
	game->player_down = mlx_load_png("srcs/textures/player_down.png");
	game->p_right = mlx_texture_to_image(game->mlx, game->player);
	game->p_left = mlx_texture_to_image(game->mlx, game->player_left);
	game->p_up = mlx_texture_to_image(game->mlx, game->player_up);
	game->p_down = mlx_texture_to_image(game->mlx, game->player_down);
	mlx_image_to_window(game->mlx, game->p_right, (x - 1) * 32, (y - 1) * 32);
	mlx_image_to_window(game->mlx, game->p_left, (x - 1) * 32, (y - 1) * 32);
	mlx_image_to_window(game->mlx, game->p_up, (x - 1) * 32, (y - 1) * 32);
	mlx_image_to_window(game->mlx, game->p_down, (x - 1) * 32, (y - 1) * 32);
}

void	ft_init_player(t_imgdata *game, char **map)
{
	int	y;
	int	x;
	int	ref;

	ref = 0;
	y = -1;
	while (map[++y] && ref == 0)
	{
		x = -1;
		while (map[y][++x] && ref == 0)
			if (map[y][x] == 'P')
				ref = 1;
	}
	game->player_state = malloc(sizeof(int) * 5);
	ft_texture_player(game, x, y);
	game->y_axis = (y - 1) * 32;
	game->x_axis = (x - 1) * 32;
	game->player_state[0] = 0;
	game->p_left->instances[0].z -= 1000;
	game->player_state[1] = -1000;
	game->p_up->instances[0].z -= 1100;
	game->player_state[2] = -1100;
	game->p_down->instances[0].z -= 1200;
	game->player_state[3] = -1200;
}
