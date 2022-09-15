/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:24:07 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/12 17:35:59 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_end_game(t_imgdata *data2)
{
	mlx_close_window(data2->mlx);
}

void	ft_del_texture(t_imgdata *game)
{
	mlx_delete_texture(game->enemy_right);
	mlx_delete_texture(game->enemy_left);
	mlx_delete_texture(game->enemy_down);
	mlx_delete_texture(game->enemy_up);
	mlx_delete_texture(game->player);
	mlx_delete_texture(game->player_down);
	mlx_delete_texture(game->player_up);
	mlx_delete_texture(game->player_left);
	mlx_delete_texture(game->exit1);
	mlx_delete_texture(game->exit);
	mlx_delete_texture(game->collect_0);
	mlx_delete_texture(game->collect_1);
	mlx_delete_texture(game->collect_2);
	mlx_delete_texture(game->collect_3);
	mlx_delete_texture(game->collect_4);
	mlx_delete_texture(game->collect_5);
	mlx_delete_texture(game->collect_6);
	mlx_delete_texture(game->collect_7);
	mlx_delete_texture(game->collect_8);
	mlx_delete_texture(game->collect_9);
	mlx_delete_texture(game->wall);
}

void	ft_free_pointers(t_imgdata *game, char **map)
{
	free(game->player_state);
	free(game->obs_x);
	free(game->obs_y);
	free(game->col_x);
	free(game->col_y);
	free(game->col_state);
	free(game->ext_x);
	free(game->ext_y);
	free(game->enemy_state_up);
	free(game->enemy_state_down);
	free(game->enemy_state_left);
	free(game->enemy_state_right);
	free(game->enemy_xy);
	free(game->e_y_axis);
	free(game->e_x_axis);
	free(game->enemy_loop);
	free(game->len_enemy);
	free_map(map);
}
