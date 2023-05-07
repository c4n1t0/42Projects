/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_game_0_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:56:55 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/24 08:41:24 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
**  Delete hook images
*/

void	cub_delete_images(t_cub *cub)
{
	if (cub->flag == 1)
	{
		mlx_delete_image(cub->mlx, cub->ctrl);
		cub->flag = 0;
	}
	mlx_delete_image(cub->mlx, cub->txt);
	mlx_delete_image(cub->mlx, cub->m_player);
	mlx_delete_image(cub->mlx, cub->mini);
	mlx_delete_image(cub->mlx, cub->player);
}

/*
**  Player actions in hook
*/

void	cub_action(t_cub *cub)
{
	static int		c[3] = {0, 0, 0};

	if (mlx_is_key_down(cub->mlx, MLX_KEY_P)
		|| mlx_is_mouse_down(cub->mlx, MLX_MOUSE_BUTTON_MIDDLE))
		cub->actions->punch = 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_K) && cub->actions->shoot == 0)
		cub->actions->kick = 1;
	if ((mlx_is_mouse_down(cub->mlx, MLX_MOUSE_BUTTON_RIGHT)
			|| mlx_is_key_down(cub->mlx, MLX_KEY_G)) && cub->actions->kick == 0)
		cub->actions->shoot = 1;
	if (cub->actions->punch == 1)
		cub->actions->punch = cub_animated_sprite_left_hand(cub);
	if (cub->actions->kick == 1)
	{
		cub->s_map->i_gun[0]->instances->z = -6500;
		cub->actions->kick = cub_animated_sprite_player_leg(cub);
		if (cub->actions->kick == 0)
			cub->s_map->i_gun[0]->instances->z = 80;
	}
	if (cub->actions->shoot == 1)
		cub->actions->shoot = cub_animated_sprite_right_hand(cub);
	cub_door_ctrl(cub, c);
}

/*
**  Load new´s images for hook
*/

void	cub_set_load_images(t_cub *cub)
{
	cub->player = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->mini = mlx_new_image(cub->mlx, cub->s_map->len_line * 4,
			ft_n_maps_lines(cub->s_map->map) * 4);
	cub->m_player = mlx_new_image(cub->mlx, 3, 3);
	ft_background(cub);
	ft_definepoint_dda(cub);
	ft_set_minimap(cub);
	ft_sprites (cub);
	mlx_image_to_window(cub->mlx, cub->player, 0, 0);
	cub->player->instances->z = 1;
	ft_memset(cub->m_player->pixels, 100, cub->m_player->width
		* cub->m_player->height * sizeof(int));
	mlx_image_to_window(cub->mlx, cub->m_player, 40, 40);
	cub->m_player->instances->z = 20;
}

/*
**  Display controls options in hook
*/

void	cub_view_controls(t_cub *cub)
{	
	if (mlx_is_key_down(cub->mlx, MLX_KEY_C))
	{
		cub->txt = mlx_put_string(cub->mlx,
				"W-Forward S-Back A-Left D-Right <-Look >-Look Right",
				10, 440);
		cub->txt->instances->z = 210;
		cub->ctrl = mlx_put_string(cub->mlx,
				"SPACE -Open door P- Punch G- Shoot K- Kick",
				10, 460);
		cub->ctrl->instances->z = 200;
		cub->flag = 1;
	}
	else
	{
		cub->txt = mlx_put_string(cub->mlx, "Press C to view controls",
				10, 460);
		cub->txt->instances->z = 210;
	}
}
