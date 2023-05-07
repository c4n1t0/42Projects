/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:02:02 by bjimenez          #+#    #+#             */
/*   Updated: 2023/04/19 23:39:53 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
**	Define sprite data
*/

static void	define_data(t_cub *cub, int i)
{
		cub->gd_sprt->pos_x = cub->sprt[i]->x - cub->x_axis;
		cub->gd_sprt->pos_y = cub->sprt[i]->y - cub->y_axis;
		cub->gd_sprt->f_inv = 1 / ((cub->dda->cam_px * cub->dda->vector_y)
			- (cub->dda->cam_py * cub->dda->vector_x));
		cub->gd_sprt->x_mv = cub->gd_sprt->f_inv * ((cub->gd_sprt->pos_x
				* cub->dda->vector_y) - (cub->gd_sprt->pos_y
				* cub->dda->vector_x));
		cub->gd_sprt->y_mv = cub->gd_sprt->f_inv * ((-1 * cub->dda->cam_py
				* cub->gd_sprt->pos_x)
			+ (cub->dda->cam_px * cub->gd_sprt->pos_y));
		cub->gd_sprt->x_sprt_view = (int)((WIDTH / 2) * (1 + cub->gd_sprt->x_mv
				/ cub->gd_sprt->y_mv));
}

/*
**	Define sprite x and y limits
*/

static void	define_limits(t_cub *cub)
{
	cub->gd_sprt->h = (int)(HEIGHT / cub->gd_sprt->y_mv);
	cub->gd_sprt->hstart = ((-1 * cub->gd_sprt->h) / 2) + (HEIGHT / 2);
	cub->gd_sprt->hend = (cub->gd_sprt->h / 2) + (HEIGHT / 2);
	cub->gd_sprt->w = (int)fabs(HEIGHT / cub->gd_sprt->y_mv);
	cub->gd_sprt->wstart = ((-1 * cub->gd_sprt->w) / 2)
		+ cub->gd_sprt->x_sprt_view;
	cub->gd_sprt->wend = (cub->gd_sprt->w / 2) + cub->gd_sprt->x_sprt_view;
	if (cub->gd_sprt->wstart < 0)
		cub->gd_sprt->wstart = 0;
	else if (cub->gd_sprt->wstart > WIDTH)
		cub->gd_sprt->wstart = WIDTH - 1;
	if (cub->gd_sprt->wend > WIDTH)
		cub->gd_sprt->wend = WIDTH - 1;
	else if (cub->gd_sprt->wend < 0)
		cub->gd_sprt->wend = 0;
}

/*
**	Sprites on map
*/

void	ft_sprites(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->gd_sprt->nbr)
	{
		define_data(cub, i);
		define_limits(cub);
		j = cub->gd_sprt->wstart;
		while (j < cub->gd_sprt->wend)
		{
			cub->gd_sprt->x_tx = (double)cub->sprt[i]->tx_sprt->width
				/ (double)(cub->gd_sprt->wend - cub->gd_sprt->wstart);
			if (cub->gd_sprt->y_mv > 0 && j > 0 && j < WIDTH
				&& cub->gd_sprt->y_mv < cub->dda->perp_list[j])
				ft_bresenham_s(cub, j, i);
			j++;
		}
	}
}

/*
**	Define sprite coord
*/

void	cub_sprt_coord(t_cub *cub)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	i = 0;
	while (i < cub->gd_sprt->nbr)
	{
		x = 0;
		while (cub->s_map->map[y][x])
		{
			if (cub->s_map->map[y][x] == 'U')
			{
				cub->sprt[i]->x = (double)x + 0.5;
				cub->sprt[i]->y = (double)y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

/*
**	Init sprites
*/

void	ft_init_sprites(t_cub *cub)
{
	int	i;

	i = -1;
	cub_search_sprite_map(cub);
	cub->sprt = (t_sprt **)malloc(sizeof(t_sprt *) * cub->gd_sprt->nbr + 1);
	while (++i < cub->gd_sprt->nbr)
	{
		cub->sprt[i] = (t_sprt *)malloc(sizeof(t_sprt));
		cub->sprt[i]->tx_sprt
			= mlx_load_png(cub->s_map->t_spr);
	}
	cub->sprt[i] = NULL;
	cub_sprt_coord(cub);
}
