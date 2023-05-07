/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bresen_s_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:12:52 by bjimenez          #+#    #+#             */
/*   Updated: 2023/04/24 09:56:35 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
** Get sprite texture pixel colour
*/

unsigned int	color(t_cub *cub, int x, int y, int texture)
{
	int				pixel;
	double			y_tx;
	t_color			color;

	y_tx = (double)cub->sprt[texture]->tx_sprt->height
		/ (double)(cub->gd_sprt->hend - cub->gd_sprt->hstart);
	pixel = ((int)(y_tx * (y - cub->gd_sprt->hstart))
			*cub->sprt[texture]->tx_sprt->width * 4)
		+ (int)(cub->gd_sprt->x_tx * (x - cub->gd_sprt->wstart)) * 4;
	color.r = cub->sprt[texture]->tx_sprt->pixels[pixel];
	color.g = cub->sprt[texture]->tx_sprt->pixels[pixel + 1];
	color.b = cub->sprt[texture]->tx_sprt->pixels[pixel + 2];
	color.a = 255;
	color.col = ((color.r << 24) | (color.g << 16) | (color.b << 8) | color.a);
	return (color.col);
}

/*
**	Draw sprite lines from x1,y1 to x2,y2
*/

void	ft_bresenham_s(t_cub *cub, int x_coord, int texture)
{
	t_draw_line	data;

	data.dy = (cub->gd_sprt->hend - cub->gd_sprt->hstart);
	data.dx = (x_coord - x_coord);
	ft_define_disp_i(&data);
	ft_define_disp_r(&data);
	ft_define_adv(&data, x_coord, cub->gd_sprt->hstart);
	while (data.x != x_coord || data.y != cub->gd_sprt->hend)
	{
		if (data.x < WIDTH && data.x >= 0 && data.x >= cub->gd_sprt->wstart
			&& data.x <= cub->gd_sprt->wend && data.y < HEIGHT && data.y >= 0
			&& data.y >= cub->gd_sprt->hstart && data.y <= cub->gd_sprt->hend
			&& color(cub, x_coord, data.y, texture) != 0x000000FF)
			mlx_put_pixel(cub->player, x_coord, data.y,
				color(cub, x_coord, data.y, texture));
		ft_define_type_adv(&data);
	}
}
