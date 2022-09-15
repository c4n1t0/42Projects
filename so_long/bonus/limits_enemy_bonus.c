/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:27:50 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/12 22:53:27 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_enemy_w(t_imgdata *const data2)
{
	int	i;

	i = 0;
	while (i < data2->len_enemy[0])
	{
		if (data2->y_axis > data2->e_y_axis[i]
			&& data2->x_axis > (data2->e_x_axis[i] - 28)
			&& data2->x_axis < (data2->e_x_axis[i] + 28)
			&& data2->y_axis > (data2->e_y_axis[i] - 28)
			&& data2->y_axis < (data2->e_y_axis[i] + 28))
			return (ft_printf("####--- You Lose! ---####\n"), -1);
		i++;
	}
	return (0);
}

int	ft_enemy_s(t_imgdata *const data2)
{
	int	i;

	i = 0;
	while (i < data2->len_enemy[0])
	{
		if (data2->y_axis < data2->e_y_axis[i]
			&& data2->x_axis > (data2->e_x_axis[i] - 28)
			&& data2->x_axis < (data2->e_x_axis[i] + 28)
			&& data2->y_axis > (data2->e_y_axis[i] - 28)
			&& data2->y_axis < (data2->e_y_axis[i] + 28))
			return (ft_printf("####--- You Lose! ---####\n"), -1);
		i++;
	}
	return (0);
}

int	ft_enemy_a(t_imgdata *const data2)
{
	int	i;

	i = 0;
	while (i < data2->len_enemy[0])
	{
		if (data2->x_axis > data2->e_x_axis[i]
			&& data2->y_axis > (data2->e_y_axis[i] - 28)
			&& data2->y_axis < (data2->e_y_axis[i] + 28)
			&& data2->x_axis > (data2->e_x_axis[i] - 28)
			&& data2->x_axis < (data2->e_x_axis[i] + 28))
			return (ft_printf("####--- You Lose! ---####\n"), -1);
		i++;
	}
	return (0);
}

int	ft_enemy_d(t_imgdata *const data2)
{
	int	i;

	i = 0;
	while (i < data2->len_enemy[0])
	{
		if (data2->x_axis < data2->e_x_axis[i]
			&& data2->y_axis > (data2->e_y_axis[i] - 28)
			&& data2->y_axis < (data2->e_y_axis[i] + 28)
			&& data2->x_axis > (data2->e_x_axis[i] - 28)
			&& data2->x_axis < (data2->e_x_axis[i] + 28))
			return (ft_printf("####--- You Lose! ---####\n"), -1);
		i++;
	}
	return (0);
}
