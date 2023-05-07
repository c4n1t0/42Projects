/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:11:04 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/18 11:43:03 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
