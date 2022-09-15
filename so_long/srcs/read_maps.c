/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:23:47 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/02 12:36:07 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_extension_check(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
		p++;
	p = p - 4;
	if (*p != '.')
		return (-1);
	p++;
	if (*p != 'b')
		return (-1);
	p++;
	if (*p != 'e')
		return (-1);
	p++;
	if (*p != 'r')
		return (-1);
	p++;
	if (*p != '\0')
		return (-1);
	return (0);
}

int	ft_count_line(char *root)
{
	int		i;
	int		fd;
	char	*p;

	i = 0;
	fd = open(root, O_RDONLY);
	if (fd == -1)
		return (-1);
	p = get_next_line(fd);
	if (p)
		i++;
	while (p)
	{
		free(p);
		p = get_next_line(fd);
		i++;
	}
	free(p);
	close(fd);
	return (i);
}

char	**ft_save_map(int lines, char *root)
{
	char	**map;
	int		fd;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (lines + 1));
	fd = open(root, O_RDONLY);
	while (lines > 0)
	{
		map[i] = get_next_line(fd);
		i++;
		lines--;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
