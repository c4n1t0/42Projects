/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:49:11 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/12 23:08:57 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_up(t_imgdata *data2)
{
	ft_position_player_up(data2);
	if (data2->y_axis > 32 && ft_wall_w(data2) == 0)
	{
		data2->p_right->instances[0].y -= 3;
		data2->p_left->instances[0].y -= 3;
		data2->p_up->instances[0].y -= 3;
		data2->p_down->instances[0].y -= 3;
		data2->y_axis = data2->y_axis - 3;
		data2->counter += 3;
		if (data2->counter % 30 == 0)
			ft_printf("Numero de movimientos: %d\n", (data2->counter / 30));
		ft_collect_game_w(data2);
	}
}

void	ft_key_down(t_imgdata *data2)
{
	ft_position_player_down(data2);
	if (data2->y_axis < (data2->height - 64) && ft_wall_s(data2) == 0)
	{
		data2->p_right->instances[0].y += 3;
		data2->p_left->instances[0].y += 3;
		data2->p_up->instances[0].y += 3;
		data2->p_down->instances[0].y += 3;
		data2->y_axis = data2->y_axis + 3;
		data2->counter += 3;
		if (data2->counter % 30 == 0)
			ft_printf("Numero de movimientos: %d\n", (data2->counter / 30));
		ft_collect_game_s(data2);
	}
}

void	ft_key_right(t_imgdata *data2)
{
	ft_position_player_right(data2);
	if (data2->x_axis < (data2->width - 64) && ft_wall_d(data2) == 0)
	{
		data2->p_right->instances[0].x += 3;
		data2->p_left->instances[0].x += 3;
		data2->p_up->instances[0].x += 3;
		data2->p_down->instances[0].x += 3;
		data2->x_axis = data2->x_axis + 3;
		data2->counter += 3;
		if (data2->counter % 30 == 0)
			ft_printf("Numero de movimientos: %d\n", (data2->counter / 30));
		ft_collect_game_d(data2);
	}
}

void	ft_key_left(t_imgdata *data2)
{
	ft_position_player_left(data2);
	if (data2->x_axis > 32 && ft_wall_a(data2) == 0)
	{
		data2->p_right->instances[0].x -= 3;
		data2->p_left->instances[0].x -= 3;
		data2->p_up->instances[0].x -= 3;
		data2->p_down->instances[0].x -= 3;
		data2->x_axis = data2->x_axis - 3;
		data2->counter += 3;
		if (data2->counter % 30 == 0)
			ft_printf("Numero de movimientos: %d\n", (data2->counter / 30));
		ft_collect_game_a(data2);
	}
}

void	ft_finish_comp(t_imgdata *data2)
{
	if ((ft_exit_game_w(data2) == -1 && ft_check_col(data2) == 0)
		|| (ft_exit_game_s(data2) == -1 && ft_check_col(data2) == 0)
		|| (ft_exit_game_a(data2) == -1 && ft_check_col(data2) == 0)
		|| (ft_exit_game_d(data2) == -1 && ft_check_col(data2) == 0))
	{
		ft_printf("####--- You Win!! ---####\n");
		ft_end_game(data2);
	}
}
