/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsLook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:12:47 by bjimenez          #+#    #+#             */
/*   Updated: 2023/04/18 11:35:58 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
**	Move player view (right)
*/

void	ft_look_right(t_cub *cub)
{
	double	prev_vector_x;
	double	prev_cam_x;

	prev_vector_x = cub->dda->vector_x;
	cub->dda->vector_x = cub->dda->vector_x * cos(cub->vel_giro)
		- cub->dda->vector_y * sin(cub->vel_giro);
	cub->dda->vector_y = prev_vector_x * sin(cub->vel_giro) + cub->dda->vector_y
		* cos(cub->vel_giro);
	prev_cam_x = cub->dda->cam_px;
	cub->dda->cam_px = cub->dda->cam_px * cos(cub->vel_giro) - cub->dda->cam_py
		* sin(cub->vel_giro);
	cub->dda->cam_py = prev_cam_x * sin(cub->vel_giro) + cub->dda->cam_py
		* cos(cub->vel_giro);
}

/*
**	Move player view (left)
*/

void	ft_look_left(t_cub *cub)
{
	double	prev_vector_x;
	double	prev_cam_x;

	prev_vector_x = cub->dda->vector_x;
	cub->dda->vector_x = cub->dda->vector_x * cos(cub->vel_giro)
		+ cub->dda->vector_y * sin(cub->vel_giro);
	cub->dda->vector_y = -prev_vector_x * sin(cub->vel_giro)
		+ cub->dda->vector_y * cos(cub->vel_giro);
	prev_cam_x = cub->dda->cam_px;
	cub->dda->cam_px = cub->dda->cam_px * cos(cub->vel_giro) + cub->dda->cam_py
		* sin(cub->vel_giro);
	cub->dda->cam_py = -prev_cam_x * sin(cub->vel_giro) + cub->dda->cam_py
		* cos(cub->vel_giro);
}

/*
**	Move mouse player view (left/right)
*/

void	ft_look_mouse(t_cub *cub)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx_get_mouse_pos(cub->mlx, &x, &y);
	if (WIDTH / 2 < x)
		ft_look_right(cub);
	else if (WIDTH / 2 > x)
		ft_look_left(cub);
}
