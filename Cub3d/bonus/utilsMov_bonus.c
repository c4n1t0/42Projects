/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsMov_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:59:32 by bjimenez          #+#    #+#             */
/*   Updated: 2023/04/18 11:37:04 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
**	Move player forward
*/

void	ft_move_forward(t_cub *cub)
{
	if (cub->dda->v_perp_euc_player > 0.6)
		cub->x_axis += cub->vel_mov * cub->dda->vector_x;
	if (cub->dda->v_perp_euc_player > 0.6)
		cub->y_axis += cub->vel_mov * cub->dda->vector_y;
}

/*
**	Move player back
*/

void	ft_move_back(t_cub *cub)
{
	if (cub->s_map->map[(int)cub->y_axis][(int)(cub->x_axis - cub->dda->vector_x
		* cub->vel_mov)] == '0')
		cub->x_axis -= cub->vel_mov * cub->dda->vector_x;
	if (cub->s_map->map[(int)(cub->y_axis - cub->dda->vector_y
			* cub->vel_mov)][(int)cub->x_axis] == '0')
		cub->y_axis -= cub->vel_mov * cub->dda->vector_y;
}

/*
**	Move player left
*/

void	ft_move_left(t_cub *cub)
{
	if (cub->s_map->map[(int)(cub->y_axis + (-cub->dda->vector_x * cub->vel_mov
				+ 0.1))][(int)(cub->x_axis + (cub->dda->vector_y * cub->vel_mov
				+ 0.1))] == '0' && cub->s_map->map[(int)(cub->y_axis
			+ (-cub->dda->vector_x * cub->vel_mov - 0.1))][(int)(cub->x_axis
			+ (cub->dda->vector_y * cub->vel_mov - 0.1))] == '0')
	{
		cub->x_axis = cub->x_axis + (cub->vel_mov * (cub->dda->vector_y));
		cub->y_axis = cub->y_axis + (cub->vel_mov * (-cub->dda->vector_x));
	}
}

/*
**	Move player right
*/

void	ft_move_right(t_cub *cub)
{
	if (cub->s_map->map[(int)(cub->y_axis + (cub->dda->vector_x * cub->vel_mov)
			+ 0.1)][(int)(cub->x_axis + (-cub->dda->vector_y * cub->vel_mov)
			+ 0.1)] == '0' && cub->s_map->map[(int)(cub->y_axis
			+ (cub->dda->vector_x * cub->vel_mov) - 0.1)][(int)(cub->x_axis
			+ (-cub->dda->vector_y * cub->vel_mov) - 0.1)] == '0')
	{
		cub->x_axis = cub->x_axis + (cub->vel_mov * (-cub->dda->vector_y));
		cub->y_axis = cub->y_axis + (cub->vel_mov * (cub->dda->vector_x));
	}
}
