/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:04:05 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/12 23:19:53 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	hook(void *data)
{
	t_imgdata	*data2;

	data2 = data;
	if (mlx_is_key_down(data2->mlx, MLX_KEY_ESCAPE))
		ft_end_game(data2);
	if (mlx_is_key_down(data2->mlx, MLX_KEY_W)
		|| mlx_is_key_down(data2->mlx, MLX_KEY_UP))
		ft_key_up(data2);
	if (mlx_is_key_down(data2->mlx, MLX_KEY_S)
		|| mlx_is_key_down(data2->mlx, MLX_KEY_DOWN))
		ft_key_down(data2);
	if (mlx_is_key_down(data2->mlx, MLX_KEY_A)
		|| mlx_is_key_down(data2->mlx, MLX_KEY_LEFT))
		ft_key_left(data2);
	if (mlx_is_key_down(data2->mlx, MLX_KEY_D)
		|| mlx_is_key_down(data2->mlx, MLX_KEY_RIGHT))
		ft_key_right(data2);
	if (ft_check_col(data2) == 0)
		ft_open_door(data2);
	ft_finish_comp(data2);
}

void	ft_start_game(char **map, int lines)
{
	t_imgdata	game;

	ft_size_windows(&game, map);
	game.mlx = mlx_init(game.width, game.height, TITLE,
			false);
	if (!game.mlx)
		exit(EXIT_FAILURE);
	ft_wall_in_len(&game, lines, map);
	ft_wall_in_block(&game, lines, map);
	ft_collect_in_len(&game, lines, map);
	ft_init_col_state(&game);
	ft_collect_in_block(&game, lines, map);
	ft_exit_in_len(&game, lines, map);
	ft_exit_in_block(&game, lines, map);
	ft_init_wall(&game, map);
	ft_init_collect(&game, map);
	ft_init_exit(&game, map);
	ft_init_player(&game, map);
	mlx_loop_hook(game.mlx, &hook, &game);
	mlx_loop(game.mlx);
	ft_del_texture(&game);
	mlx_terminate(game.mlx);
	ft_free_pointers(&game, map);
}
