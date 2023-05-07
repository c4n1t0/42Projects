/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsCub_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:15:18 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/18 11:56:05 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Map length lines
*/

int	ft_n_maps_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

/*
**  duoble pointer length
*/

int	ft_len_double_pointer(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
**	Free double pointer memory
*/

void	free_double_p(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/*
**  Delete \n from gnl
*/

void	cub_remove_final_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			str[i] = '\0';
		else
			i++;
	}
}

/*
**	Free str1 memory and join str2
*/

char	*ft_free_and_save(char *str1, char *str2)
{
	char	*temp;

	temp = ft_strjoin(str1, str2);
	free(str1);
	return (temp);
}
