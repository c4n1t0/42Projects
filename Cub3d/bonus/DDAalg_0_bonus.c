/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDAalg_0_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:29:30 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/24 17:46:39 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
**	Ray analysis and DDA
*/

void	ft_definepoint_dda(t_cub *cub)
{
	cub->dda->x_coord = 0;
	while (cub->dda->x_coord++ < WIDTH)
	{
		ft_init_cam_ray(cub, cub->dda->x_coord);
		ft_define_xy_size(cub);
		ft_step_and_lts(cub);
		cub->dda->wall_coll = 0;
		ft_dda(cub);
		ft_vert_dim_wall(cub, cub->dda->x_coord);
		if (cub->s_map->map[cub->dda->aux_y_axis][cub->dda->aux_x_axis] == 'D')
			ft_bresenham(cub->dda->x_coord, cub, 4);
		else if (cub->dda->cardinal_w_c == 1 && (cub->dda->vector_y > 0
				|| cub->dda->rayo_y > 0) && cub->dda->step_y > 0)
			ft_bresenham(cub->dda->x_coord, cub, 1);
		else if (cub->dda->cardinal_w_c == 1 && (cub->dda->vector_y < 0
				|| cub->dda->rayo_y < 0) && cub->dda->step_y < 0)
			ft_bresenham(cub->dda->x_coord, cub, 0);
		else if (cub->dda->cardinal_w_c == 0 && (cub->dda->vector_x > 0
				|| cub->dda->rayo_x > 0) && cub->dda->step_x > 0)
			ft_bresenham(cub->dda->x_coord, cub, 3);
		else if (cub->dda->cardinal_w_c == 0 && (cub->dda->vector_x < 0
				|| cub->dda->rayo_x < 0) && cub->dda->step_x < 0)
			ft_bresenham(cub->dda->x_coord, cub, 2);
	}
}
