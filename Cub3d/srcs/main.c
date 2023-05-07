/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:36:30 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/24 12:39:54 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	t_cub	*cub;

	cub = param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
	if (mlx_is_mouse_down(cub->mlx, MLX_MOUSE_BUTTON_LEFT))
		ft_look_mouse(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		ft_look_right(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		ft_look_left(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
		ft_move_forward(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
		ft_move_back(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		ft_move_left(cub);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		ft_move_right(cub);
	mlx_delete_image(cub->mlx, cub->player);
	cub->player = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	ft_background(cub);
	ft_definepoint_dda(cub);
	mlx_image_to_window(cub->mlx, cub->player, 0, 0);
	cub->player->instances->z = 1;
}

int	main(int argc, char **argv)
{
	t_cub	cub;
	t_map	map;
	t_dda	dda;
	t_m_map	m_map;

	cub.s_map = &map;
	cub.dda = &dda;
	cub.m_map = &m_map;
	if (argc < 2)
		return (ft_putstr_fd("Error\nGame MAP missing!!\n", 2), 1);
	if (argc != 2)
		return (ft_putstr_fd("Error\nInvalid arguments\n", 2), 1);
	if (cub_check_map(&map, argv[1]) == 1)
		return (cub_free_memory(&map), 1);
	cub.mlx = mlx_init(WIDTH, HEIGHT,
			"Cub3D El yogur de limón 🍋 @ 42_school_Malaga", false);
	if (!cub.mlx)
		exit(EXIT_FAILURE);
	ft_init_cub3d(&cub);
	mlx_loop_hook(cub.mlx, &hook, &cub);
	mlx_loop(cub.mlx);
	cub_free_memory_mlx(&cub);
	cub_free_memory(&map);
	return (EXIT_SUCCESS);
}
