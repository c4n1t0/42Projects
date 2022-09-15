/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits_collect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:56:45 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/04 08:44:14 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collect_game_w(t_imgdata *data2)
{
	int	i;

	i = 0;
	while (i < data2->len_collect)
	{
		if (data2->y_axis > data2->col_y[i] && data2->x_axis > (data2->col_x[i]
				- 16) && data2->x_axis < (data2->col_x[i] + 16)
			&& data2->y_axis > (data2->col_y[i] - 16)
			&& data2->y_axis < (data2->col_y[i] + 16))
		{
			if (data2->col_state[i] == 0)
			{
				mlx_set_instance_depth(&data2->i_collect->instances[i], -1100);
				data2->game_collect = data2->game_collect + 1;
				data2->col_state[i] = 1;
				ft_printf("Collectables recogidos: %d   de %d\n",
					data2->game_collect, data2->len_collect);
			}
		}
		i++;
	}
}

void	ft_collect_game_s(t_imgdata *data2)
{
	int	i;

	i = 0;
	while (i < data2->len_collect)
	{
		if (data2->y_axis < data2->col_y[i] && data2->x_axis > (data2->col_x[i]
				- 16) && data2->x_axis < (data2->col_x[i] + 16)
			&& data2->y_axis > (data2->col_y[i] - 16)
			&& data2->y_axis < (data2->col_y[i] + 16))
		{
			if (data2->col_state[i] == 0)
			{
				mlx_set_instance_depth(&data2->i_collect->instances[i], -1100);
				data2->game_collect = data2->game_collect + 1;
				data2->col_state[i] = 1;
				ft_printf("Collectables recogidos: %d   de %d\n",
					data2->game_collect, data2->len_collect);
			}
		}
		i++;
	}
}

void	ft_collect_game_a(t_imgdata *data2)
{
	int	i;

	i = 0;
	while (i < data2->len_collect)
	{
		if (data2->x_axis > data2->col_x[i] && data2->y_axis > (data2->col_y[i]
				- 16) && data2->y_axis < (data2->col_y[i] + 16)
			&& data2->x_axis > (data2->col_x[i] - 16)
			&& data2->x_axis < (data2->col_x[i] + 16))
		{
			if (data2->col_state[i] == 0)
			{
				mlx_set_instance_depth(&data2->i_collect->instances[i], -1100);
				data2->game_collect = data2->game_collect + 1;
				data2->col_state[i] = 1;
				ft_printf("Collectables recogidos: %d   de %d\n",
					data2->game_collect, data2->len_collect);
			}
		}
		i++;
	}
}

void	ft_collect_game_d(t_imgdata *data2)
{
	int	i;

	i = 0;
	while (i < data2->len_collect)
	{
		if (data2->x_axis < data2->col_x[i] && data2->y_axis > (data2->col_y[i]
				- 16) && data2->y_axis < (data2->col_y[i] + 16)
			&& data2->x_axis > (data2->col_x[i] - 16)
			&& data2->x_axis < (data2->col_x[i] + 16))
		{
			if (data2->col_state[i] == 0)
			{
				mlx_set_instance_depth(&data2->i_collect->instances[i], -1100);
				data2->game_collect = data2->game_collect + 1;
				data2->col_state[i] = 1;
				ft_printf("Collectables recogidos: %d   de %d\n",
					data2->game_collect, data2->len_collect);
			}
		}
		i++;
	}
}
