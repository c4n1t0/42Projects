/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:28:29 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/12 17:32:57 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_sub1_col_sprite(t_imgdata *data2, int i, int y)
{
	if (y == 0 && data2->col_state[i] == 0)
	{	
		data2->i_collect_1->instances[i].z += 2100;
		data2->i_collect_0->instances[i].z -= 2000;
	}
	if (y == 1 && data2->col_state[i] == 0)
	{	
		data2->i_collect_2->instances[i].z += 2200;
		data2->i_collect_1->instances[i].z -= 2100;
	}
	if (y == 2 && data2->col_state[i] == 0)
	{
		data2->i_collect_3->instances[i].z += 2300;
		data2->i_collect_2->instances[i].z -= 2200;
	}
	if (y == 3 && data2->col_state[i] == 0)
	{
		data2->i_collect_4->instances[i].z += 2400;
		data2->i_collect_3->instances[i].z -= 2300;
	}
	if (y == 4 && data2->col_state[i] == 0)
	{
		data2->i_collect_5->instances[i].z += 2500;
		data2->i_collect_4->instances[i].z -= 2400;
	}
}

void	ft_sub2_col_sprite(t_imgdata *data2, int i, int y)
{
	if (y == 5 && data2->col_state[i] == 0)
	{
		data2->i_collect_6->instances[i].z += 2600;
		data2->i_collect_5->instances[i].z -= 2500;
	}
	if (y == 6 && data2->col_state[i] == 0)
	{
		data2->i_collect_7->instances[i].z += 2700;
		data2->i_collect_6->instances[i].z -= 2600;
	}
	if (y == 7 && data2->col_state[i] == 0)
	{
		data2->i_collect_8->instances[i].z += 2800;
		data2->i_collect_7->instances[i].z -= 2700;
	}
	if (y == 8 && data2->col_state[i] == 0)
	{
		data2->i_collect_9->instances[i].z += 2900;
		data2->i_collect_8->instances[i].z -= 2800;
	}
	if (y == 9 && data2->col_state[i] == 0)
	{
		data2->i_collect_0->instances[i].z += 2000;
		data2->i_collect_9->instances[i].z -= 2900;
	}
}
