/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_delete_0_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:48:16 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/24 12:14:58 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	if (map->t_door)
		free(map->t_door);
	if (map->t_spr)
		free(map->t_spr);
	close (map->fd);
}

/*
**	Unallocate MLX memory
*/

void	cub_unallocate_memory(t_cub *cub)
{
	int	i;

	i = 0;
	free(cub->s_map->i_arm);
	free(cub->s_map->i_gun);
	free(cub->s_map->i_leg);
	free(cub->s_map->arm);
	free(cub->s_map->gun);
	free(cub->s_map->leg);
	free(cub->s_map->textures);
	while (cub->sprt[i])
		free(cub->sprt[i++]);
	free(cub->sprt);
}

/*
**	Unallocate MLX textures and memory
*/

void	cub_free_memory_mlx(t_cub *cub)
{
	int	i;

	i = 0;
	free(cub->dda);
	mlx_delete_image(cub->mlx, cub->sprites);
	mlx_delete_image(cub->mlx, cub->txt);
	mlx_delete_image(cub->mlx, cub->m_player);
	mlx_delete_image(cub->mlx, cub->mini);
	mlx_delete_image(cub->mlx, cub->player);
	while (i <= 6 || i <= cub->gd_sprt->nbr)
	{
		if (i < 5 && cub->s_map->textures[i])
			mlx_delete_texture(cub->s_map->textures[i]);
		if (i < 6 && cub->s_map->gun[i])
			mlx_delete_texture(cub->s_map->gun[i]);
		if (i < 2 && cub->s_map->leg[i])
			mlx_delete_texture(cub->s_map->leg[i]);
		if (i < 3 && cub->s_map->arm[i])
			mlx_delete_texture(cub->s_map->arm[i]);
		if (i < cub->gd_sprt->nbr && cub->sprt[i]->tx_sprt)
			mlx_delete_texture(cub->sprt[i]->tx_sprt);
		i++;
	}
	cub_unallocate_memory(cub);
	mlx_terminate(cub->mlx);
}

/*
**  Load walls and door textures to array
*/

void	ft_init_texture(t_cub *cub)
{
	cub->s_map->textures[0] = mlx_load_png(cub->s_map->t_no);
	cub->s_map->textures[1] = mlx_load_png(cub->s_map->t_so);
	cub->s_map->textures[2] = mlx_load_png(cub->s_map->t_we);
	cub->s_map->textures[3] = mlx_load_png(cub->s_map->t_ea);
	cub->s_map->textures[4] = mlx_load_png(cub->s_map->t_door);
	cub->s_map->textures[5] = NULL;
}

/*
**	Allocate memory for textures & images
*/

void	cub_allocate_memory(t_cub *cub)
{
	cub->s_map->textures = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *)
			* 6);
	cub->s_map->arm = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *) * 4);
	cub->s_map->leg = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *) * 3);
	cub->s_map->gun = (mlx_texture_t **)malloc(sizeof(mlx_texture_t *) * 7);
	cub->s_map->i_arm = malloc(sizeof(mlx_image_t) * 4);
	cub->s_map->i_leg = malloc(sizeof(mlx_image_t) * 3);
	cub->s_map->i_gun = malloc(sizeof(mlx_image_t) * 7);
	cub->dda = malloc(sizeof(t_dda));
	cub->dda->d_w = (double)WIDTH;
	if (!cub->s_map->textures || !cub->s_map->arm || !cub->s_map->leg
		|| !cub->s_map->gun || !cub->s_map->i_arm || !cub->s_map->i_leg
		|| !cub->s_map->i_gun || !cub->dda)
	{
		cub_free_memory_mlx(cub);
		cub_free_memory(cub->s_map);
		ft_putstr_fd("Error\nUnallocate Memory\n", 2);
		exit(1);
	}
}
