/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:58:40 by bjimenez          #+#    #+#             */
/*   Updated: 2023/04/20 09:49:38 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
**	Draw blocks in minimap
*/

void	ft_put_block(int x, int y, t_cub *cub, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->m_map->y_wall)
	{
		j = 0;
		while (j < cub->m_map->x_wall)
		{
			mlx_put_pixel(cub->player, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

/*
**	Draw minimap -> Walls, Doors and minimap background
*/

void	ft_print_lines(t_cub *cub)
{
	if (cub->m_map->x >= 0 && cub->m_map->x < cub->s_map->len_line)
	{
		if (cub->s_map->map[cub->m_map->y][cub->m_map->x] == '1')
			ft_put_block(cub->m_map->col * cub->m_map->x_wall, cub->m_map->line
				* cub->m_map->y_wall, cub, 0x4884B6FF);
		else if (cub->s_map->map[cub->m_map->y][cub->m_map->x] == 'D')
			ft_put_block(cub->m_map->col * cub->m_map->x_wall, cub->m_map->line
				* cub->m_map->y_wall, cub, 0x7D705BFF);
		else
			ft_put_block(cub->m_map->col * cub->m_map->x_wall, cub->m_map->line
				* cub->m_map->y_wall, cub, 0xC8E1F7FF);
	}
	else
		ft_put_block(cub->m_map->col * cub->m_map->x_wall, cub->m_map->line
			* cub->m_map->y_wall, cub, 0xC8E1F7FF);
	cub->m_map->col++;
	cub->m_map->x++;
}

/*
**	Draw minimap -> Rest
*/

void	ft_print_rest(t_cub *cub)
{
	while (cub->m_map->x <= (int)cub->x_axis + 10)
	{
		ft_put_block(cub->m_map->col * cub->m_map->x_wall, cub->m_map->line
			* cub->m_map->y_wall, cub, 0xC8E1F7FF);
		cub->m_map->col++;
		cub->m_map->x++;
	}		
}

/*
**	Draw minimap
*/

void	ft_print_mini(t_cub *cub)
{
	cub->m_map->y = (int)cub->y_axis - 10;
	cub->m_map->line = 0;
	while (cub->m_map->y <= (int)cub->y_axis + 10)
	{
		cub->m_map->x = (int)cub->x_axis - 10;
		cub->m_map->col = 0;
		if (cub->m_map->y >= 0 && cub->m_map->y
			< ft_len_double_pointer(cub->s_map->map))
			while (cub->m_map->x <= (int)cub->x_axis + 10)
				ft_print_lines(cub);
		else
			ft_print_rest(cub);
		cub->m_map->y++;
		cub->m_map->line++;
	}
}

/*
**	Init minimap value and print
*/

void	ft_set_minimap(t_cub *cub)
{
	cub->m_map->x_wall = 4;
	cub->m_map->y_wall = 4;
	ft_print_mini(cub);
}
