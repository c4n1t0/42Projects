/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:31:07 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/04 09:11:16 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_position_player_up(t_imgdata *data2)
{
	if (data2->player_state[2] != 0)
	{
		data2->p_up->instances[0].z += 1100;
		data2->player_state[2] = 0;
		if (data2->player_state[0] == 0)
		{
			data2->p_right->instances[0].z -= 1300;
			data2->player_state[0] = -1300;
		}
		else if (data2->player_state[1] == 0)
		{
			data2->p_left->instances[0].z -= 1000;
			data2->player_state[1] = -1000;
		}
		else if (data2->player_state[3] == 0)
		{
			data2->p_down->instances[0].z -= 1200;
			data2->player_state[3] = -1200;
		}
	}
}

void	ft_position_player_down(t_imgdata *data2)
{
	if (data2->player_state[3] != 0)
	{
		data2->p_down->instances[0].z += 1200;
		data2->player_state[3] = 0;
		if (data2->player_state[0] == 0)
		{
			data2->p_right->instances[0].z -= 1300;
			data2->player_state[0] = -1300;
		}
		else if (data2->player_state[1] == 0)
		{
			data2->p_left->instances[0].z -= 1000;
			data2->player_state[1] = -1000;
		}
		else if (data2->player_state[2] == 0)
		{
			data2->p_up->instances[0].z -= 1100;
			data2->player_state[2] = -1100;
		}
	}
}

void	ft_position_player_left(t_imgdata *data2)
{
	if (data2->player_state[1] != 0)
	{
		data2->p_left->instances[0].z += 1000;
		data2->player_state[1] = 0;
		if (data2->player_state[0] == 0)
		{
			data2->p_right->instances[0].z -= 1300;
			data2->player_state[0] = -1300;
		}
		else if (data2->player_state[2] == 0)
		{
			data2->p_up->instances[0].z -= 1100;
			data2->player_state[2] = -1100;
		}
		else if (data2->player_state[3] == 0)
		{
			data2->p_down->instances[0].z -= 1200;
			data2->player_state[3] = -1200;
		}
	}
}

void	ft_position_player_right(t_imgdata *data2)
{
	if (data2->player_state[0] != 0)
	{
		data2->p_right->instances[0].z += 1300;
		data2->player_state[0] = 0;
		if (data2->player_state[1] == 0)
		{
			data2->p_left->instances[0].z -= 1000;
			data2->player_state[1] = -1000;
		}
		else if (data2->player_state[2] == 0)
		{
			data2->p_up->instances[0].z -= 1100;
			data2->player_state[2] = -1100;
		}
		else if (data2->player_state[3] == 0)
		{
			data2->p_down->instances[0].z -= 1200;
			data2->player_state[3] = -1200;
		}
	}
}
