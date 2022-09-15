/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:24:07 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/03 22:00:41 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_end_game(t_imgdata *data2)
{
	mlx_delete_image(data2->mlx, data2->p_down);
	mlx_delete_image(data2->mlx, data2->p_up);
	mlx_delete_image(data2->mlx, data2->p_left);
	mlx_delete_image(data2->mlx, data2->p_right);
	mlx_delete_image(data2->mlx, data2->i_exit1);
	mlx_delete_image(data2->mlx, data2->i_exit);
	mlx_delete_image(data2->mlx, data2->i_collect);
	mlx_delete_image(data2->mlx, data2->i_wall);
	mlx_close_window(data2->mlx);
}

void	ft_del_texture(t_imgdata *game)
{
	mlx_delete_texture(game->player);
	mlx_delete_texture(game->player_down);
	mlx_delete_texture(game->player_up);
	mlx_delete_texture(game->player_left);
	mlx_delete_texture(game->exit1);
	mlx_delete_texture(game->exit);
	mlx_delete_texture(game->collect);
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
	free_map(map);
}
