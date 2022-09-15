/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits_exit_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:48:26 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/04 09:11:28 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_exit_game_w(t_imgdata *data2)
{
	int	i;

	i = 0;
	while (i < data2->len_exit)
	{
		if (data2->y_axis > data2->ext_y[i] && data2->x_axis > (data2->ext_x[i]
				- 16) && data2->x_axis < (data2->ext_x[i] + 16)
			&& data2->y_axis > (data2->ext_y[i] - 16)
			&& data2->y_axis < (data2->ext_y[i] + 16))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_exit_game_s(t_imgdata *data2)
{
	int	i;

	i = 0;
	while (i < data2->len_exit)
	{
		if (data2->y_axis < data2->ext_y[i] && data2->x_axis > (data2->ext_x[i]
				- 16) && data2->x_axis < (data2->ext_x[i] + 16)
			&& data2->y_axis > (data2->ext_y[i] - 16)
			&& data2->y_axis < (data2->ext_y[i] + 16))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_exit_game_a(t_imgdata *data2)
{
	int	i;

	i = 0;
	while (i < data2->len_exit)
	{
		if (data2->x_axis > data2->ext_x[i] && data2->y_axis > (data2->ext_y[i]
				- 16) && data2->y_axis < (data2->ext_y[i] + 16)
			&& data2->x_axis > (data2->ext_x[i] - 16)
			&& data2->x_axis < (data2->ext_x[i] + 16))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_exit_game_d(t_imgdata *data2)
{
	int	i;

	i = 0;
	while (i < data2->len_exit)
	{
		if (data2->x_axis < data2->ext_x[i] && data2->y_axis > (data2->ext_y[i]
				- 16) && data2->y_axis < (data2->ext_y[i] + 16)
			&& data2->x_axis > (data2->ext_x[i] - 16)
			&& data2->x_axis < (data2->ext_x[i] + 16))
			return (-1);
		i++;
	}
	return (0);
}
