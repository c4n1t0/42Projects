/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits_collect_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:56:45 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/12 16:43:39 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_clean_collect(t_imgdata *data2, int i)
{
	mlx_set_instance_depth(&data2->i_collect_0->instances[i], -2000);
	mlx_set_instance_depth(&data2->i_collect_1->instances[i], -2100);
	mlx_set_instance_depth(&data2->i_collect_2->instances[i], -2200);
	mlx_set_instance_depth(&data2->i_collect_3->instances[i], -2300);
	mlx_set_instance_depth(&data2->i_collect_4->instances[i], -2400);
	mlx_set_instance_depth(&data2->i_collect_5->instances[i], -2500);
	mlx_set_instance_depth(&data2->i_collect_6->instances[i], -2600);
	mlx_set_instance_depth(&data2->i_collect_7->instances[i], -2700);
	mlx_set_instance_depth(&data2->i_collect_8->instances[i], -2800);
	mlx_set_instance_depth(&data2->i_collect_9->instances[i], -2900);
}

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
				ft_clean_collect(data2, i);
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
				ft_clean_collect(data2, i);
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
				ft_clean_collect(data2, i);
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
				ft_clean_collect(data2, i);
				data2->game_collect = data2->game_collect + 1;
				data2->col_state[i] = 1;
				ft_printf("Collectables recogidos: %d   de %d\n",
					data2->game_collect, data2->len_collect);
			}
		}
		i++;
	}
}
