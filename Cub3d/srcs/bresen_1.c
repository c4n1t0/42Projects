/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:12:52 by bjimenez          #+#    #+#             */
/*   Updated: 2023/04/18 11:38:52 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Get texture pixel colour
*/

unsigned int	ft_color(t_cub *cub, int y, int texture)
{
	int				pixel;
	double			y_tx;
	double			x_tx;
	double			point_w;
	t_color			color;

	if (cub->dda->cardinal_w_c == 0)
		point_w = cub->y_axis + cub->dda->v_perp_euc * cub->dda->rayo_y;
	if (cub->dda->cardinal_w_c == 1)
		point_w = cub->x_axis + cub->dda->v_perp_euc * cub->dda->rayo_x;
	x_tx = point_w * cub->s_map->textures[texture]->width;
	if ((cub->dda->cardinal_w_c == 0 && cub->dda->rayo_x > 0)
		|| (cub->dda->cardinal_w_c == 1 && cub->dda->rayo_y < 0))
		x_tx = cub->s_map->textures[texture]->width - x_tx - 1;
	y_tx = (double)cub->s_map->textures[texture]->height
		/ (double)(cub->dda->end_vert_wall - cub->dda->star_vert_wall);
	pixel = ((int)(y_tx * (double)(y - cub->dda->star_vert_wall))
			*cub->s_map->textures[texture]->width * 4)
		+ ((int)x_tx % cub->s_map->textures[texture]->width) * 4;
	color.r = cub->s_map->textures[texture]->pixels[pixel];
	color.g = cub->s_map->textures[texture]->pixels[pixel + 1];
	color.b = cub->s_map->textures[texture]->pixels[pixel + 2];
	color.a = cub->s_map->textures[texture]->pixels[pixel + 3];
	color.col = ((color.r << 24) | (color.g << 16) | (color.b << 8) | color.a);
	return (color.col);
}

/*
**	Define inclined displacement
*/

void	ft_define_disp_i(t_draw_line *data)
{
	if (data->dy >= 0)
		data->disp_i_y = 1;
	else
	{
		data->dy *= -1;
		data->disp_i_y = -1;
	}
	if (data->dx >= 0)
		data->disp_i_x = 1;
	else
	{
		data->dx *= -1;
		data->disp_i_x = -1;
	}
}

/*
**	Define straight displacement
*/

void	ft_define_disp_r(t_draw_line *data)
{
	int	aux;

	if (data->dx >= data->dy)
	{
		data->disp_r_y = 0;
		data->disp_r_x = data->disp_i_x;
	}
	else
	{
		data->disp_r_x = 0;
		data->disp_r_y = data->disp_i_y;
		aux = data->dx;
		data->dx = data->dy;
		data->dy = aux;
	}
}

/*
**	Define movement
*/

void	ft_define_adv(t_draw_line *data, int x1, int y1)
{
	data->x = x1;
	data->y = y1;
	data->adv_r = 2 * data->dy;
	data->adv = data->adv_r - data->dx;
	data->adv_i = data->adv - data->dx;
}

/*
** Define movement type
*/

void	ft_define_type_adv(t_draw_line *data)
{
	if (data->adv >= 0)
	{
		data->x = data->x + data->disp_i_x;
		data->y = data->y + data->disp_i_y;
		data->adv = data->adv + data->adv_i;
	}
	else
	{
		data->x = data->x + data->disp_r_x;
		data->y = data->y + data->disp_r_y;
		data->adv = data->adv + data->adv_r;
	}
}
