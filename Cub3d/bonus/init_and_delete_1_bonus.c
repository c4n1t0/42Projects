/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_delete_1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:54:02 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/24 12:18:01 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
**  Load first person textures to array from PNG
*/

void	cub_load_texture_image_first_person(t_cub *cub)
{
	cub->s_map->arm[0] = mlx_load_png("./textures/hand.png");
	cub->s_map->arm[1] = mlx_load_png("./textures/hand1.png");
	cub->s_map->arm[2] = mlx_load_png("./textures/hand2.png");
	cub->s_map->leg[0] = mlx_load_png("./textures/leg1.png");
	cub->s_map->leg[1] = mlx_load_png("./textures/leg2.png");
	cub->s_map->gun[0] = mlx_load_png("./textures/pistol-1.png");
	cub->s_map->gun[1] = mlx_load_png("./textures/pistol-2.png");
	cub->s_map->gun[2] = mlx_load_png("./textures/pistol-3.png");
	cub->s_map->gun[3] = mlx_load_png("./textures/pistol-4.png");
	cub->s_map->gun[4] = mlx_load_png("./textures/pistol-5.png");
	cub->s_map->gun[5] = mlx_load_png("./textures/pistol-6.png");
	cub->s_map->i_arm[0] = mlx_texture_to_image(cub->mlx, cub->s_map->arm[0]);
	cub->s_map->i_arm[1] = mlx_texture_to_image(cub->mlx, cub->s_map->arm[1]);
	cub->s_map->i_arm[2] = mlx_texture_to_image(cub->mlx, cub->s_map->arm[2]);
	cub->s_map->i_leg[0] = mlx_texture_to_image(cub->mlx, cub->s_map->leg[0]);
	cub->s_map->i_leg[1] = mlx_texture_to_image(cub->mlx, cub->s_map->leg[1]);
	cub->s_map->i_gun[0] = mlx_texture_to_image(cub->mlx, cub->s_map->gun[0]);
	cub->s_map->i_gun[1] = mlx_texture_to_image(cub->mlx, cub->s_map->gun[1]);
	cub->s_map->i_gun[2] = mlx_texture_to_image(cub->mlx, cub->s_map->gun[2]);
	cub->s_map->i_gun[3] = mlx_texture_to_image(cub->mlx, cub->s_map->gun[3]);
	cub->s_map->i_gun[4] = mlx_texture_to_image(cub->mlx, cub->s_map->gun[4]);
	cub->s_map->i_gun[5] = mlx_texture_to_image(cub->mlx, cub->s_map->gun[5]);
}

/*
**  Load first person image and position to windows
*/

void	cub_init_image_to_window_first_person(t_cub *cub)
{
	mlx_image_to_window(cub->mlx, cub->s_map->i_arm[0], 140, 300);
	cub->s_map->i_arm[0]->instances->z = 60;
	mlx_image_to_window(cub->mlx, cub->s_map->i_arm[1], 140, 300);
	cub->s_map->i_arm[1]->instances->z = -1000;
	mlx_image_to_window(cub->mlx, cub->s_map->i_arm[2], 140, 300);
	cub->s_map->i_arm[2]->instances->z = -2000;
	mlx_image_to_window(cub->mlx, cub->s_map->i_leg[0], 400, 350);
	cub->s_map->i_leg[0]->instances->z = -4000;
	mlx_image_to_window(cub->mlx, cub->s_map->i_leg[1], 430, 150);
	cub->s_map->i_leg[1]->instances->z = -5000;
	mlx_image_to_window(cub->mlx, cub->s_map->i_gun[0], 460, 200);
	cub->s_map->i_gun[0]->instances->z = 80;
	mlx_image_to_window(cub->mlx, cub->s_map->i_gun[1], 460, 180);
	cub->s_map->i_gun[1]->instances->z = -1500;
	mlx_image_to_window(cub->mlx, cub->s_map->i_gun[2], 460, 160);
	cub->s_map->i_gun[2]->instances->z = -2500;
	mlx_image_to_window(cub->mlx, cub->s_map->i_gun[3], 460, 160);
	cub->s_map->i_gun[3]->instances->z = -3500;
	mlx_image_to_window(cub->mlx, cub->s_map->i_gun[4], 460, 160);
	cub->s_map->i_gun[4]->instances->z = -4500;
	mlx_image_to_window(cub->mlx, cub->s_map->i_gun[5], 460, 180);
	cub->s_map->i_gun[5]->instances->z = -5500;
}

int	cub_check_textures(t_cub *cub)
{
	int	i;

	i = 0;
	while (i <= 6 || i <= cub->gd_sprt->nbr)
	{
		if (i < 5 && !cub->s_map->textures[i])
			return (1);
		if (!cub->s_map->gun[i] && i < 6)
			return (1);
		if (!cub->s_map->leg[i] && i < 2)
			return (1);
		if (!cub->s_map->arm[i] && i < 3)
			return (1);
		if (i < cub->gd_sprt->nbr && !cub->sprt[i]->tx_sprt)
			return (1);
		i++;
	}
	return (0);
}

void	cub_force_exit(t_cub *cub)
{
	cub_free_memory_mlx(cub);
	cub_free_memory(cub->s_map);
	ft_putstr_fd("Error\nIncorrect PNG!\n", 2);
	exit(1);
}
