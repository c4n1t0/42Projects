/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:20:00 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/18 10:51:13 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
**	Change instances z value
*/

void	cub_change_instance(t_cub *cub, int n_img_a, int z_a, int z_b)
{
	cub->s_map->i_gun[n_img_a]->instances->z = z_a;
	if (n_img_a == 5)
		cub->s_map->i_gun[0]->instances->z = z_b;
	else
		cub->s_map->i_gun[n_img_a + 1]->instances->z = z_b;
}

/*
**	Player Sprite: right hand
*/

int	cub_animated_sprite_right_hand(t_cub *cub)
{
	static int	i = 0;

	i++;
	if (i == 3)
	{
		if (cub->s_map->i_gun[0]->instances->z > 0)
			cub_change_instance(cub, 0, -6500, 60);
		else if (cub->s_map->i_gun[1]->instances->z > 0)
			cub_change_instance(cub, 1, -1500, 60);
		else if (cub->s_map->i_gun[2]->instances->z > 0)
			cub_change_instance(cub, 2, -2500, 60);
		else if (cub->s_map->i_gun[3]->instances->z > 0)
			cub_change_instance(cub, 3, -3500, 60);
		else if (cub->s_map->i_gun[4]->instances->z > 0)
			cub_change_instance(cub, 4, -4500, 60);
		else if (cub->s_map->i_gun[5]->instances->z > 0)
		{
			cub_change_instance(cub, 5, -5500, 60);
			i = 0;
			return (0);
		}
		i = 0;
	}
	return (1);
}

/*
**	Player Sprite: left hand
*/

int	cub_animated_sprite_left_hand(t_cub *cub)
{
	static int	i = 0;

	i++;
	if (i == 7)
	{
		if (cub->s_map->i_arm[0]->instances->z > 0)
		{
			cub->s_map->i_arm[0]->instances->z = -3000;
			cub->s_map->i_arm[1]->instances->z = 60;
		}
		else if (cub->s_map->i_arm[1]->instances->z > 0)
		{
			cub->s_map->i_arm[1]->instances->z = -1000;
			cub->s_map->i_arm[2]->instances->z = 60;
		}
		else if (cub->s_map->i_arm[2]->instances->z > 0)
		{
			cub->s_map->i_arm[2]->instances->z = -2000;
			cub->s_map->i_arm[0]->instances->z = 60;
			i = 0;
			return (0);
		}
		i = 0;
	}
	return (1);
}

/*
**  Player Sprite: right leg
*/

int	cub_animated_sprite_player_leg(t_cub *cub)
{
	static int	i = 0;

	i++;
	if (i == 12)
	{
		if (cub->s_map->i_leg[0]->instances->z > 0)
		{
			cub->s_map->i_leg[0]->instances->z = -5000;
			cub->s_map->i_leg[1]->instances->z = 30;
		}
		else if (cub->s_map->i_leg[1]->instances->z > 0)
		{
			cub->s_map->i_leg[0]->instances->z = -4000;
			cub->s_map->i_leg[1]->instances->z = -5000;
			i = 0;
			return (0);
		}
		else if (cub->s_map->i_leg[0]->instances->z < 0)
		{
			cub->s_map->i_leg[0]->instances->z = 30;
			cub->s_map->i_leg[1]->instances->z = -4000;
		}
		i = 0;
	}
	return (1);
}
