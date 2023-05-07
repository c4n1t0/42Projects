/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDAalg_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:27:35 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/25 08:30:15 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Ray analysis and DDA
*/

void	ft_definepoint_dda(t_cub *cub)
{
	int		x_coord;

	x_coord = 0;
	while (x_coord++ < WIDTH)
	{
		ft_init_cam_ray(cub, x_coord);
		ft_define_xy_size(cub);
		ft_step_and_lts(cub);
		cub->dda->wall_coll = 0;
		ft_dda(cub);
		ft_vert_dim_wall(cub, x_coord);
		if (cub->dda->cardinal_w_c == 1 && (cub->dda->vector_y > 0
				|| cub->dda->rayo_y > 0) && cub->dda->step_y > 0)
			ft_bresenham(x_coord, cub, 1);
		else if (cub->dda->cardinal_w_c == 1 && (cub->dda->vector_y < 0
				|| cub->dda->rayo_y < 0) && cub->dda->step_y < 0)
			ft_bresenham(x_coord, cub, 0);
		else if (cub->dda->cardinal_w_c == 0 && (cub->dda->vector_x > 0
				|| cub->dda->rayo_x > 0) && cub->dda->step_x > 0)
			ft_bresenham(x_coord, cub, 3);
		else if (cub->dda->cardinal_w_c == 0 && (cub->dda->vector_x < 0
				|| cub->dda->rayo_x < 0) && cub->dda->step_x < 0)
			ft_bresenham(x_coord, cub, 2);
	}
}
