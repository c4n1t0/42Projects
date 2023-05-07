/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap_4_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:11:04 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/23 11:05:54 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
**	Check colour value
*/

int	cub_check_color(char *data)
{
	char	**colour;
	int		i;

	i = 0;
	colour = ft_split(data, ',');
	if (ft_len_double_pointer(colour) != 3)
		return (free_double_p(colour), 1);
	while (colour[i])
	{
		if (ft_strlen(colour[i]) > 3)
			return (free_double_p(colour), 1);
		if (ft_atoi(colour[i]) > 255 || ft_atoi(colour[1]) < 0)
			return (free_double_p(colour), 1);
		i++;
	}
	free_double_p(colour);
	return (0);
}

/*
**	Read sprites in map and return quantity
*/

void	cub_search_sprite_map(t_cub *cub)
{
	int		x;
	char	*p;

	cub->gd_sprt->nbr = 0;
	x = 0;
	while (cub->s_map->map[x])
	{
		p = cub->s_map->map[x];
		while (*p)
		{
			if (*p == 'U')
				cub->gd_sprt->nbr++;
			p++;
		}
		x++;
	}
}

/*
**	Check space and tabs
*/

char	*cub_detect_route(char *gnl)
{
	char	*p;

	p = &gnl[2];
	while ((*p == ' ' || *p == '\t') && *p != '\n')
		p++;
	return (p);
}

/*
**	Search biggest line of map
*/

void	cub_big_str_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) > (size_t)map->len_line)
			map->len_line = ft_strlen(map->map[i]);
		i++;
	}
}
