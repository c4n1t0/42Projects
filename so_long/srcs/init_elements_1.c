/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:12:55 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/04 08:41:58 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_exit(t_imgdata *game, char **map)
{
	int	y;
	int	x;
	int	i;

	y = -1;
	i = 0;
	game->exit = mlx_load_png("srcs/textures/door_close.png");
	game->exit1 = mlx_load_png("srcs/textures/door_open.png");
	game->i_exit = mlx_texture_to_image(game->mlx, game->exit);
	game->i_exit1 = mlx_texture_to_image(game->mlx, game->exit1);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx, game->i_exit, (x * 32), (y
						* 32));
				mlx_image_to_window(game->mlx, game->i_exit1, (x * 32), (y
						* 32));
				game->i_exit1->instances[i++].z -= 1000;
			}
		}
	}
}

void	ft_exit_in_len(t_imgdata *game, int lines, char **map)
{
	int				y;
	unsigned long	x;

	y = 1;
	x = 1;
	game->len_exit = 0;
	while (y < (lines - 2))
	{
		x = 1;
		while (x < (ft_strlen(map[y]) - 2))
		{
			if (map[y][x] == 'E')
				game->len_exit = game->len_exit + 1;
			x++;
		}
		y++;
	}
	game->ext_x = malloc((game->len_exit + 1) * sizeof(int));
	game->ext_y = malloc((game->len_exit + 1) * sizeof(int));
}

void	ft_exit_in_block(t_imgdata *game, int lines, char **map)
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
			if (map[y][x] == 'E')
			{
				game->ext_x[i] = x * 32 + 8;
				game->ext_y[i] = y * 32 + 8;
				i++;
			}
			x++;
		}
		y++;
	}
}
