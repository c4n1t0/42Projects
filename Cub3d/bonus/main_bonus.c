/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:36:30 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/24 12:17:50 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
**	Draw background
*/

void	ft_background(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < (HEIGHT / 2))
				mlx_put_pixel(cub->player, x, y, cub->s_map->color_roof);
			else if (y >= (HEIGHT / 2) && (y < HEIGHT))
				mlx_put_pixel(cub->player, x, y, cub->s_map->color_floor);
			x++;
		}
		y++;
	}
}

/*
** Keyboard events and actions
*/

void	hook(void *param)
{
	t_cub			*cub;

	cub = param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
	if (mlx_is_mouse_down(cub->mlx, MLX_MOUSE_BUTTON_LEFT))
		ft_look_mouse(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT)
		&& mlx_is_key_down(cub->mlx, MLX_KEY_LEFT) == 0)
		ft_look_right(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT)
		&& mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT) == 0)
		ft_look_left(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
		ft_move_forward(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
		ft_move_back(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		ft_move_left(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		ft_move_right(cub);
	cub_delete_images(cub);
	cub_action(cub);
	cub_set_load_images(cub);
	cub_view_controls(cub);
}

/*
**  Init cub3d data
*/

void	ft_init_cub3d(t_cub *cub)
{
	static t_actions	actions;

	cub->actions = &actions;
	cub_allocate_memory(cub);
	define_actions(cub);
	cub_load_texture_image_first_person(cub);
	cub_init_image_to_window_first_person(cub);
	ft_init_texture (cub);
	ft_init_sprites(cub);
	if (cub_check_textures(cub) == 1)
		cub_force_exit(cub);
	cub->player = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	ft_background(cub);
	ft_definepoint_dda(cub);
	mlx_image_to_window(cub->mlx, cub->player, 0, 0);
	mlx_set_mouse_pos(cub->mlx, WIDTH / 2, HEIGHT / 2);
	cub->mini = mlx_new_image(cub->mlx, cub->s_map->len_line * 4,
			ft_n_maps_lines(cub->s_map->map) * 4);
	ft_set_minimap(cub);
	cub->m_player = mlx_new_image(cub->mlx, 3, 3);
	cub->txt = mlx_put_string(cub->mlx, "Press C to view controls", 10, 460);
	cub->txt->instances->z = 210;
	ft_sprites (cub);
}

int	main(int argc, char **argv)
{
	t_cub		cub;
	t_map		map;
	t_dda		dda;
	t_m_map		m_map;
	t_gd_sprt	gd_sprt;

	cub.s_map = &map;
	cub.dda = &dda;
	cub.m_map = &m_map;
	cub.gd_sprt = &gd_sprt;
	if (argc < 2)
		return (ft_putstr_fd("Error\nGame MAP missing!!\n", 2), 1);
	if (argc != 2)
		return (ft_putstr_fd("Error\nInvalid arguments\n", 2), 1);
	if (cub_check_map(&map, argv[1]) == 1)
		return (cub_free_memory(&map), 1);
	cub.mlx = mlx_init(WIDTH, HEIGHT, "Cub3D 🍋 @ 42_School-Málaga", false);
	if (!cub.mlx)
		exit(EXIT_FAILURE);
	ft_init_cub3d(&cub);
	mlx_loop_hook(cub.mlx, &hook, &cub);
	mlx_loop(cub.mlx);
	cub_free_memory_mlx(&cub);
	cub_free_memory(&map);
	return (EXIT_SUCCESS);
}
