/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_hooks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:16:52 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/12 16:36:28 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_enemy_hooks_up(t_imgdata *data2, int i)
{
	if (data2->enemy_state_up[i] == 0)
	{
		data2->enemy_state_up[i] = 1;
		data2->enemy_state_down[i] = 0;
		data2->e_up->instances[i].z += 1500;
		data2->e_down->instances[i].z -= 1500;
	}
	data2->e_up->instances[i].y -= 1;
	data2->e_down->instances[i].y -= 1;
	data2->e_left->instances[i].y -= 1;
	data2->e_right->instances[i].y -= 1;
	data2->e_y_axis[i] = data2->e_y_axis[i] - 1;
	if (ft_wall_w_enemy(data2, i) == -1 || data2->e_y_axis[i] <= 32)
		data2->enemy_loop[i] = 1;
}

void	ft_enemy_hooks_down(t_imgdata *data2, int i)
{
	if (data2->enemy_state_down[i] == 0)
	{
		data2->enemy_state_up[i] = 0;
		data2->enemy_state_down[i] = 1;
		data2->e_down->instances[i].z += 1500;
		data2->e_up->instances[i].z -= 1500;
	}
	data2->e_up->instances[i].y += 1;
	data2->e_down->instances[i].y += 1;
	data2->e_left->instances[i].y += 1;
	data2->e_right->instances[i].y += 1;
	data2->e_y_axis[i] = data2->e_y_axis[i] + 1;
	if (ft_wall_s_enemy(data2, i) == -1 || data2->e_y_axis[i] >= (data2->height
			- 64))
		data2->enemy_loop[i] = 0;
}

void	ft_enemy_hooks_right(t_imgdata *data2, int i)
{
	if (data2->enemy_state_up[i] == 1
		|| data2->enemy_state_down[i] == 1)
	{
		data2->enemy_state_up[i] = 0;
		data2->enemy_state_down[i] = 0;
		data2->e_up->instances[i].z -= 1500;
		data2->e_down->instances[i].z -= 1550;
		data2->enemy_state_right[i] = 1;
		data2->e_right->instances[i].z += 1700;
	}
	if (data2->enemy_state_right[i] == 0)
	{
		data2->enemy_state_right[i] = 1;
		data2->enemy_state_left[i] = 0;
		data2->e_right->instances[i].z += 1700;
		data2->e_left->instances[i].z -= 1600;
	}
		data2->e_left->instances[i].x += 1;
		data2->e_right->instances[i].x += 1;
		data2->e_up->instances[i].x += 1;
		data2->e_down->instances[i].x += 1;
		data2->e_x_axis[i] = data2->e_x_axis[i] + 1;
	if (ft_wall_d_enemy(data2, i) == -1
		|| data2->e_x_axis[i] >= (data2->width - 64))
		data2->enemy_loop[i] = 1;
}

void	ft_enemy_hooks_left(t_imgdata *data2, int i)
{
	if (data2->enemy_state_up[i] == 1
		|| data2->enemy_state_down[i] == 1)
	{
		data2->enemy_state_up[i] = 0;
		data2->enemy_state_down[i] = 0;
		data2->e_up->instances[i].z -= 1500;
		data2->e_down->instances[i].z -= 1550;
		data2->enemy_state_right[i] = 1;
		data2->e_right->instances[i].z += 1700;
	}
	if (data2->enemy_state_left[i] == 0)
	{
		data2->enemy_state_right[i] = 0;
		data2->enemy_state_left[i] = 1;
		data2->e_right->instances[i].z -= 1700;
		data2->e_left->instances[i].z += 1600;
	}
	data2->e_left->instances[i].x -= 1;
	data2->e_right->instances[i].x -= 1;
	data2->e_up->instances[i].x -= 1;
	data2->e_down->instances[i].x -= 1;
	data2->e_x_axis[i] = data2->e_x_axis[i] - 1;
	if (ft_wall_a_enemy(data2, i) == -1 || data2->e_x_axis[i] <= 32)
		data2->enemy_loop[i] = 0;
}

void	ft_enemy_hooks(t_imgdata *data2)
{
	int	i;

	i = 0;
	while (i < data2->len_enemy[0])
	{
		if (data2->enemy_xy[i] == 0)
		{
			if (data2->e_y_axis[i] > 32 && ft_wall_w_enemy(data2, i) == 0
				&& data2->enemy_loop[i] == 0)
				ft_enemy_hooks_up(data2, i);
			else
				ft_enemy_hooks_down(data2, i);
		}
		else
		{
			if (data2->e_x_axis[i] < (data2->width - 64)
				&& ft_wall_d_enemy(data2, i) == 0 && data2->enemy_loop[i] == 0)
				ft_enemy_hooks_right(data2, i);
			else if (data2->e_x_axis[i] > 32 && ft_wall_a_enemy(data2, i) == 0)
				ft_enemy_hooks_left(data2, i);
		}
		i++;
	}
}
