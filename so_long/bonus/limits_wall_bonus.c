/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits_wall_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:49:45 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/04 09:11:21 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_wall_w(t_imgdata *const data2)
{
	int	i;

	i = 0;
	while (i < data2->len_obs)
	{
		if (data2->y_axis > data2->obs_y[i] && data2->x_axis > (data2->obs_x[i]
				- 28) && data2->x_axis < (data2->obs_x[i] + 28)
			&& data2->y_axis > (data2->obs_y[i] - 32)
			&& data2->y_axis < (data2->obs_y[i] + 32))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_wall_s(t_imgdata *const data2)
{
	int	i;

	i = 0;
	while (i < data2->len_obs)
	{
		if (data2->y_axis < data2->obs_y[i] && data2->x_axis > (data2->obs_x[i]
				- 28) && data2->x_axis < (data2->obs_x[i] + 28)
			&& data2->y_axis > (data2->obs_y[i] - 32)
			&& data2->y_axis < (data2->obs_y[i] + 32))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_wall_a(t_imgdata *const data2)
{
	int	i;

	i = 0;
	while (i < data2->len_obs)
	{
		if (data2->x_axis > data2->obs_x[i] && data2->y_axis > (data2->obs_y[i]
				- 28) && data2->y_axis < (data2->obs_y[i] + 28)
			&& data2->x_axis > (data2->obs_x[i] - 32)
			&& data2->x_axis < (data2->obs_x[i] + 32))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_wall_d(t_imgdata *const data2)
{
	int	i;

	i = 0;
	while (i < data2->len_obs)
	{
		if (data2->x_axis < data2->obs_x[i] && data2->y_axis > (data2->obs_y[i]
				- 28) && data2->y_axis < (data2->obs_y[i] + 28)
			&& data2->x_axis > (data2->obs_x[i] - 32)
			&& data2->x_axis < (data2->obs_x[i] + 32))
			return (-1);
		i++;
	}
	return (0);
}
