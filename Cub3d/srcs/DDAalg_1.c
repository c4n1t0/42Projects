/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDAalg_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:59:44 by bjimenez          #+#    #+#             */
/*   Updated: 2023/04/18 11:44:34 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Init ray and cam vectors
*/

void	ft_init_cam_ray(t_cub *cub, int x_coord)
{
	cub->dda->cam = (x_coord * 2) / cub->dda->d_w -1;
	cub->dda->rayo_x = cub->dda->vector_x + cub->dda->cam_px * cub->dda->cam;
	cub->dda->rayo_y = cub->dda->vector_y + cub->dda->cam_py * cub->dda->cam;
	cub->dda->aux_x_axis = (int)cub->x_axis;
	cub->dda->aux_y_axis = (int)cub->y_axis;
}

/*
**	Define x/y length between sides (horizontal and vertical)
*/

void	ft_define_xy_size(t_cub *cub)
{
	if (cub->dda->rayo_x == 0)
		cub->dda->x_size = exp(30);
	else
		cub->dda->x_size = fabs(1 / cub->dda->rayo_x);
	if (cub->dda->rayo_y == 0)
		cub->dda->y_size = exp(30);
	else
		cub->dda->y_size = fabs(1 / cub->dda->rayo_y);
}

/*
**	Define movement direction and x/y length to first side
*/

void	ft_step_and_lts(t_cub *cub)
{
	if (cub->dda->rayo_x < 0)
	{
		cub->dda->step_x = -1;
		cub->dda->x_lts = (cub->x_axis - cub->dda->aux_x_axis)
			* cub->dda->x_size;
	}
	else
	{
		cub->dda->step_x = 1;
		cub->dda->x_lts = (cub->dda->aux_x_axis + 1.0 - cub->x_axis)
			* cub->dda->x_size;
	}
	if (cub->dda->rayo_y < 0)
	{
		cub->dda->step_y = -1;
		cub->dda->y_lts = (cub->y_axis - cub->dda->aux_y_axis)
			* cub->dda->y_size;
	}
	else
	{
		cub->dda->step_y = 1;
		cub->dda->y_lts = (cub->dda->aux_y_axis + 1.0 - cub->y_axis)
			* cub->dda->y_size;
	}
}

/*
**	DDA
*/

void	ft_dda(t_cub *cub)
{
	while (cub->dda->wall_coll == 0)
	{
		if (cub->dda->x_lts < cub->dda->y_lts)
		{
			cub->dda->x_lts += cub->dda->x_size;
			cub->dda->aux_x_axis += cub->dda->step_x;
			cub->dda->cardinal_w_c = 0;
		}
		else
		{
			cub->dda->y_lts += cub->dda->y_size;
			cub->dda->aux_y_axis += cub->dda->step_y;
			cub->dda->cardinal_w_c = 1;
		}
		if (cub->s_map->map[cub->dda->aux_y_axis][cub->dda->aux_x_axis] == '1')
			cub->dda->wall_coll = 1;
	}
}

/*
**	For x_coord: start and end y_coord
*/

void	ft_vert_dim_wall(t_cub *cub, int x_coord)
{
	if (cub->dda->cardinal_w_c == 0)
	{
		cub->dda->v_perp_euc = (cub->dda->x_lts - cub->dda->x_size);
		cub->dda->x_wall = sqrt(pow(cub->dda->v_perp_euc, 2)
				+ pow(cub->dda->x_lts, 2));
	}
	else
	{
		cub->dda->v_perp_euc = (cub->dda->y_lts - cub->dda->y_size);
		cub->dda->x_wall = sqrt(pow(cub->dda->y_lts, 2)
				- pow(cub->dda->v_perp_euc, 2));
	}
	if (x_coord == WIDTH / 2)
		cub->dda->v_perp_euc_player = cub->dda->v_perp_euc;
	cub->dda->height_pov = (int)(HEIGHT / (cub->dda->v_perp_euc));
	cub->dda->star_vert_wall = ((-1 * cub->dda->height_pov) / 2) + (HEIGHT / 2);
	cub->dda->end_vert_wall = (cub->dda->height_pov / 2) + (HEIGHT / 2);
}
