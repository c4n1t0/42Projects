/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:21:54 by bjimenez          #+#    #+#             */
/*   Updated: 2023/04/18 11:51:15 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Define map player coord
*/

void	define_map_player(t_cub *cub)
{
	int	find;

	cub->y_axis = 0;
	find = 0;
	while (cub->s_map->map[(int)cub->y_axis] && find == 0)
	{
		cub->x_axis = 0;
		while (cub->s_map->map[(int)cub->y_axis][(int)cub->x_axis] && find == 0)
		{
			if (cub->s_map->map[(int)cub->y_axis][(int)cub->x_axis] == 'N'
				|| cub->s_map->map[(int)cub->y_axis][(int)cub->x_axis] == 'S' ||
				cub->s_map->map[(int)cub->y_axis][(int)cub->x_axis] == 'E'
				|| cub->s_map->map[(int)cub->y_axis][(int)cub->x_axis] == 'W')
				return ;
			cub->x_axis++;
		}
		cub->y_axis++;
	}
}

/*
**	Offset to player vectors
*/

void	define_player_vector_sub(t_cub *cub)
{
	cub->y_axis += 0.5;
	cub->x_axis += 0.5;
}

/*
**	Define player vector
				0 , -1
				  |
	-1 , -1		  |		1 , -1
				  |
				  |
-1 , 0 ------------------------- 1 , 0
				  |
				  |
	-1 , 1		  |		1 , 1
				  |
				0 , 1

*/

void	define_player_vector(t_cub *cub)
{
	if (cub->s_map->map[(int)cub->y_axis][(int)cub->x_axis] == 'N')
	{
		cub->dda->vector_x = 0;
		cub->dda->vector_y = -1;
		define_player_vector_sub(cub);
	}
	else if (cub->s_map->map[(int)cub->y_axis][(int)cub->x_axis] == 'S')
	{
		cub->dda->vector_x = 0;
		cub->dda->vector_y = 1;
		define_player_vector_sub(cub);
	}
	else if (cub->s_map->map[(int)cub->y_axis][(int)cub->x_axis] == 'E')
	{
		cub->dda->vector_x = 1;
		cub->dda->vector_y = 0;
		define_player_vector_sub(cub);
	}
	else if (cub->s_map->map[(int)cub->y_axis][(int)cub->x_axis] == 'W')
	{
		cub->dda->vector_x = -1;
		cub->dda->vector_y = 0;
		define_player_vector_sub(cub);
	}
	cub->s_map->map[(int)cub->y_axis][(int)cub->x_axis] = '0';
}

/*
**	Define cam values
*/

void	define_cam(t_cub *cub)
{
	if (cub->dda->vector_x == 0 && cub->dda->vector_y == -1)
	{
		cub->dda->cam_px = 1;
		cub->dda->cam_py = 0;
	}
	else if (cub->dda->vector_x == 0 && cub->dda->vector_y == 1)
	{
		cub->dda->cam_px = -1;
		cub->dda->cam_py = 0;
	}
	else
	{
		cub->dda->cam_px = 0;
		if (cub->dda->vector_x < 0)
			cub->dda->cam_py = -0.60;
		else
			cub->dda->cam_py = 0.60;
	}
}
