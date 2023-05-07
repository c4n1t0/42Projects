/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap_1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:41:10 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/20 00:10:26 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
**	Check invalid data
*/

int	cub_check_data_file(char *gnl)
{
	char	*p;

	p = gnl;
	while (*p != '\0')
	{
		if (*p != ' ' && *p != '\n' && *p != '\t' && *p != '\0')
			return (ft_putstr_fd("Error\nInvalid data in file!\n", 2), 1);
		p++;
	}
	return (0);
}

/*
**  Check and save. Texture orientation
*/

int	cub_save_texture(t_map *map, char *gnl)
{
	cub_remove_final_line(gnl);
	if (ft_strnstr(gnl, "NO ", 3) && gnl[0] == 'N' && gnl[1] == 'O'
		&& map->t_no == NULL)
		map->t_no = ft_strdup(cub_detect_route(gnl));
	else if (ft_strnstr(gnl, "SO ", 3) && gnl[0] == 'S' && gnl[1] == 'O'
		&& map->t_so == NULL)
		map->t_so = ft_strdup(cub_detect_route(gnl));
	else if (ft_strnstr(gnl, "WE ", 3) && gnl[0] == 'W' && gnl[1] == 'E'
		&& map->t_we == NULL)
		map->t_we = ft_strdup(cub_detect_route(gnl));
	else if (ft_strnstr(gnl, "EA ", 3) && gnl[0] == 'E' && gnl[1] == 'A'
		&& map->t_ea == NULL)
		map->t_ea = ft_strdup(cub_detect_route(gnl));
	else if (ft_strnstr(gnl, "F ", 2) && gnl[0] == 'F' && map->c_floor == NULL)
		map->c_floor = ft_strdup(cub_detect_route(gnl));
	else if (ft_strnstr(gnl, "C ", 2) && gnl[0] == 'C' && map->c_roof == NULL)
		map->c_roof = ft_strdup(cub_detect_route(gnl));
	else if (ft_strnstr(gnl, "DOOR ", 5) && gnl[0] == 'D' && !map->t_door)
		map->t_door = ft_strdup(cub_detect_route(&gnl[3]));
	else if (ft_strnstr(gnl, "SPRITE ", 7) && gnl[0] == 'S'
		&& map->t_spr == NULL)
		map->t_spr = ft_strdup(cub_detect_route(&gnl[5]));
	else if (cub_check_data_file(gnl) == 1)
		return (1);
	return (0);
}

void	cub_print_error_texture(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
}

/*
**	Texture route error message
*/

void	cub_error_texture(int *fd, t_map *map)
{
	ft_putstr_fd("Error\nCan´t open texture:\n", 2);
	if (fd[0] < 0)
		cub_print_error_texture(map->t_no);
	if (fd[1] < 0)
		cub_print_error_texture(map->t_so);
	if (fd[2] < 0)
		cub_print_error_texture(map->t_we);
	if (fd[3] < 0)
		cub_print_error_texture(map->t_ea);
	if (fd[4] < 0)
		cub_print_error_texture(map->t_door);
	if (fd[5] < 0)
		cub_print_error_texture(map->t_spr);
}

/*
**  Check texture route
*/

int	cub_check_texture_file(t_map *map)
{
	int	fd[7];

	fd[0] = open(map->t_no, O_RDONLY);
	fd[1] = open(map->t_so, O_RDONLY);
	fd[2] = open(map->t_we, O_RDONLY);
	fd[3] = open(map->t_ea, O_RDONLY);
	fd[4] = open(map->t_door, O_RDONLY);
	fd[5] = open(map->t_spr, O_RDONLY);
	fd[6] = 0;
	if (fd[0] < 0 || fd[1] < 0 || fd[2] < 0 || fd[3] < 0 || fd[4] < 0
		|| fd[5] < 0)
	{
		fd[6] = 1;
		cub_error_texture(fd, map);
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	close(fd[4]);
	close(fd[5]);
	return (fd[6]);
}
