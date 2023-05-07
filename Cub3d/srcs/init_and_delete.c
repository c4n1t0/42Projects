/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:04:47 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/24 12:38:33 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Free struct map memory
*/

void	cub_free_memory(t_map *map)
{
	if (map->c_floor)
		free(map->c_floor);
	if (map->c_roof)
		free(map->c_roof);
	if (map->t_ea)
		free(map->t_ea);
	if (map->t_no)
		free(map->t_no);
	if (map->t_so)
		free(map->t_so);
	if (map->t_we)
		free(map->t_we);
	if (map->map)
		free_double_p(map->map);
	if (map->fd > 0)
		close (map->fd);
	if (map->t_map)
		free(map->t_map);
	close (map->fd);
}

/*
**	Unallocate MLX memory
*/

void	cub_free_memory_mlx(t_cub *cub)
{
	if (cub->s_map->textures[3])
		mlx_delete_texture(cub->s_map->textures[3]);
	if (cub->s_map->textures[2])
		mlx_delete_texture(cub->s_map->textures[2]);
	if (cub->s_map->textures[1])
		mlx_delete_texture(cub->s_map->textures[1]);
	if (cub->s_map->textures[0])
		mlx_delete_texture(cub->s_map->textures[0]);
	if (cub->s_map->textures)
		free(cub->s_map->textures);
	if (cub->dda)
		free(cub->dda);
	mlx_delete_image(cub->mlx, cub->player);
	mlx_terminate(cub->mlx);
}

/*
**  Load walls and door textures to array
*/

void	ft_init_texture(t_cub *cub)
{
	cub->s_map->textures = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *)
			* 5);
	if (!cub->s_map->textures)
	{
		cub_free_memory_mlx(cub);
		cub_free_memory(cub->s_map);
		ft_putstr_fd("Error\nUnallocated Memory\n", 2);
		exit(1);
	}
	cub->s_map->textures[0] = mlx_load_png(cub->s_map->t_no);
	cub->s_map->textures[1] = mlx_load_png(cub->s_map->t_so);
	cub->s_map->textures[2] = mlx_load_png(cub->s_map->t_we);
	cub->s_map->textures[3] = mlx_load_png(cub->s_map->t_ea);
	cub->s_map->textures[4] = NULL;
}

int	cub_check_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!cub->s_map->textures[i])
		{
			cub_free_memory(cub->s_map);
			ft_putstr_fd("Error\nIncorrect PNG!\n", 2);
			exit(1);
		}
		i++;
	}
	return (0);
}

/*
**  Init cub3d data
*/

void	ft_init_cub3d(t_cub *cub)
{
	ft_init_texture (cub);
	cub_check_textures(cub);
	cub->dda = malloc(sizeof(t_dda));
	if (!cub->dda)
	{
		cub_free_memory(cub->s_map);
		ft_putstr_fd("Error\nUnallocated Memory\n", 2);
		exit(1);
	}
	cub->dda->d_w = (double)WIDTH;
	define_map_player(cub);
	define_player_vector(cub);
	define_cam(cub);
	ft_set_color(cub);
	cub->vel_giro = 0.01745;
	cub->vel_mov = 0.08;
	cub->angulo_rotacion = 0;
	cub->player = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	ft_background(cub);
	ft_definepoint_dda(cub);
	mlx_image_to_window(cub->mlx, cub->player, 0, 0);
	mlx_set_mouse_pos(cub->mlx, WIDTH / 2, HEIGHT / 2);
}
