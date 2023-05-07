/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_game_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:01:40 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/24 09:41:38 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
**  Check open door in hook
*/

void	cub_open_door(t_cub *cub, int *c)
{
	if (mlx_is_key_down(cub->mlx, MLX_KEY_SPACE) || cub->actions->space == 1)
	{
		if (cub->actions->space == 0 && cub->s_map->map[(int)(cub->y_axis
				+ cub->dda->vector_y)][(int)(cub->x_axis
				+ cub->dda->vector_x)] == 'D')
		{
			cub->actions->space = 1;
			cub->actions->kick = 1;
		}
		if (cub->actions->space == 1 && cub->actions->kick == 0
			&& cub->s_map->map[(int)(cub->y_axis + cub->dda->vector_y)]
				[(int)(cub->x_axis + cub->dda->vector_x)] == 'D')
		{
			cub->s_map->map[(int)(cub->y_axis + cub->dda->vector_y)]
			[(int)(cub->x_axis + cub->dda->vector_x)] = '0';
			c[0] = (int)(cub->x_axis + cub->dda->vector_x);
			c[1] = (int)(cub->y_axis + cub->dda->vector_y);
			c[2] = 1;
			cub->actions->space = 0;
		}
	}	
}

/*
**  Check close door in hook
*/

void	cub_door_ctrl(t_cub *cub, int *c)
{
	if (c[2] == 1 && (((int)fabs(cub->x_axis + cub->dda->vector_x) != c[0])
			|| ((int)fabs(cub->y_axis + cub->dda->vector_y) != c[1])))
	{
		cub->s_map->map[c[1]][c[0]] = 'D';
		c[0] = 0;
		c[1] = 0;
		c[2] = 0;
	}	
	else if (cub->dda->v_perp_euc_player <= 1
		&& (cub->s_map->map[(int)cub->y_axis][(int)(cub->x_axis
			+ cub->dda->vector_x)] == 'D' || cub->s_map->map[(int)(cub->y_axis
			+ cub->dda->vector_y)][(int)(cub->x_axis)] == 'D'
			|| cub->s_map->map[(int)cub->y_axis][(int)(cub->x_axis
			- cub->dda->vector_x)] == 'D' || cub->s_map->map[(int)(cub->y_axis
			- cub->dda->vector_y)][(int)(cub->x_axis)] == 'D'))
		cub_open_door(cub, c);
}
