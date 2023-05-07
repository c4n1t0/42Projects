/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:52:47 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/18 11:37:52 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Draw lines from x1,y1 to x2,y2
*/

void	ft_bresenham(int x_coord, t_cub *cub, int texture)
{
	t_draw_line	data;

	data.dy = (cub->dda->end_vert_wall - cub->dda->star_vert_wall);
	data.dx = (x_coord - x_coord);
	ft_define_disp_i(&data);
	ft_define_disp_r(&data);
	ft_define_adv(&data, x_coord, cub->dda->star_vert_wall);
	while (data.x != x_coord || data.y != cub->dda->end_vert_wall)
	{
		if (data.x < WIDTH && data.x >= 0 && data.y < HEIGHT && data.y >= 0)
			mlx_put_pixel(cub->player, data.x, data.y,
				ft_color(cub, data.y, texture));
		ft_define_type_adv(&data);
	}
}
