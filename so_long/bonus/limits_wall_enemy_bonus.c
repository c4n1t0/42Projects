/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits_wall_enemy_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:49:45 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/11 23:34:21 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_wall_w_enemy(t_imgdata *const data2, int x)
{
	int	i;

	i = 0;
	while (i < data2->len_obs)
	{
		if (data2->e_y_axis[x] > data2->obs_y[i]
			&& data2->e_x_axis[x] > (data2->obs_x[i] - 24)
			&& data2->e_x_axis[x] < (data2->obs_x[i] + 24)
			&& data2->e_y_axis[x] > (data2->obs_y[i] - 28)
			&& data2->e_y_axis[x] < (data2->obs_y[i] + 28))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_wall_s_enemy(t_imgdata *const data2, int x)
{
	int	i;

	i = 0;
	while (i < data2->len_obs)
	{
		if (data2->e_y_axis[x] < data2->obs_y[i]
			&& data2->e_x_axis[x] > (data2->obs_x[i] - 24)
			&& data2->e_x_axis[x] < (data2->obs_x[i] + 24)
			&& data2->e_y_axis[x] > (data2->obs_y[i] - 28)
			&& data2->e_y_axis[x] < (data2->obs_y[i] + 28))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_wall_a_enemy(t_imgdata *const data2, int x)
{
	int	i;

	i = 0;
	while (i < data2->len_obs)
	{
		if (data2->e_x_axis[x] > data2->obs_x[i]
			&& data2->e_y_axis[x] > (data2->obs_y[i] - 24)
			&& data2->e_y_axis[x] < (data2->obs_y[i] + 24)
			&& data2->e_x_axis[x] > (data2->obs_x[i] - 28)
			&& data2->e_x_axis[x] < (data2->obs_x[i] + 28))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_wall_d_enemy(t_imgdata *const data2, int x)
{
	int	i;

	i = 0;
	while (i < data2->len_obs)
	{
		if (data2->e_x_axis[x] < data2->obs_x[i]
			&& data2->e_y_axis[x] > (data2->obs_y[i] - 24)
			&& data2->e_y_axis[x] < (data2->obs_y[i] + 24)
			&& data2->e_x_axis[x] > (data2->obs_x[i] - 28)
			&& data2->e_x_axis[x] < (data2->obs_x[i] + 28))
			return (-1);
		i++;
	}
	return (0);
}
