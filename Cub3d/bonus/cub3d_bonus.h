/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 00:45:55 by jaromero          #+#    #+#             */
/*   Updated: 2023/04/24 12:18:46 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <math.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
**  Define WIDTH and HEIGHT of windows
*/

# define WIDTH 800
# define HEIGHT 480

typedef struct actions
{
	int	punch;
	int	kick;
	int	shoot;
	int	space;
}				t_actions;

typedef struct sprt
{
	double			x;
	double			y;
	mlx_texture_t	*tx_sprt;
}					t_sprt;

typedef struct m_map
{
	int		x_wall;
	int		y_wall;
	int		x;
	int		y;
	int		col;
	int		line;
}				t_m_map;

typedef struct color
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;
	uint32_t	col;
}				t_color;

typedef struct gd_sprt
{
	double	pos_x;
	double	pos_y;
	double	f_inv;
	double	x_mv;
	double	y_mv;
	int		x_sprt_view;
	int		h;
	int		hstart;
	int		hend;
	int		w;
	int		wstart;
	int		wend;
	int		nbr;
	double	x_tx;
}				t_gd_sprt;

typedef struct dda
{
	double	vector_x;	
	double	vector_y;	
	double	cam_px;		
	double	cam_py;		
	double	d_w;		
	double	rayo_x;
	double	rayo_y;
	double	cam;
	int		aux_x_axis;
	int		aux_y_axis;
	double	x_lts;
	double	y_lts;
	double	x_size;
	double	y_size;
	int		step_x;
	int		step_y;
	int		wall_coll;
	int		cardinal_w_c;
	double	v_perp_euc;
	double	v_perp_euc_player;
	double	perp_list[WIDTH];
	int		height_pov;
	int		star_vert_wall;
	int		end_vert_wall;
	double	x_wall;
	int		x_coord;
}				t_dda;

/*
**	Struct of data map
*/

typedef struct map
{
	mlx_texture_t	**textures;
	mlx_texture_t	**gun;
	mlx_texture_t	**arm;
	mlx_texture_t	**leg;
	mlx_texture_t	*door;
	mlx_image_t		**i_arm;
	mlx_image_t		**i_leg;
	mlx_image_t		**i_gun;
	char			*t_no;
	char			*t_so;
	char			*t_we;
	char			*t_ea;
	char			*c_floor;
	char			*c_roof;
	char			*t_door;
	char			*t_spr;
	char			**map;
	char			*t_map;
	int				pos_player;
	int				fd;
	int				count;
	int				x_pos;
	int				y_pos;
	int				len_line;
	unsigned int	color_floor;
	unsigned int	color_roof;
}				t_map;

typedef struct cub3d
{
	mlx_t			*mlx;
	mlx_image_t		*player;
	mlx_image_t		*background;
	mlx_image_t		*m_player;
	mlx_image_t		*mini;
	mlx_image_t		*txt;
	mlx_image_t		*ctrl;
	mlx_image_t		*sprites;
	t_sprt			**sprt;
	t_gd_sprt		*gd_sprt;
	t_actions		*actions;
	int				flag;
	t_map			*s_map;
	double			vel_mov;
	double			vel_giro;
	double			angulo_rotacion;
	int				factor_x;
	int				factor_y;
	double			x_axis;
	double			y_axis;
	t_dda			*dda;
	t_m_map			*m_map;
}					t_cub;

typedef struct s_draw_line
{
	int			dy;
	int			dx;
	int			disp_i_y;
	int			disp_i_x;
	int			disp_r_x;
	int			disp_r_y;
	int			x;
	int			y;
	int			adv;
	int			adv_r;
	int			adv_i;
}				t_draw_line;

/*
**	main_bonus.c
*/

void			ft_background(t_cub *cub);

/*
**	init_and_delete_0_bonus.c
*/

void			cub_free_memory(t_map *map);
void			cub_free_memory_mlx(t_cub *cub);
void			ft_init_texture(t_cub *cub);
void			cub_allocate_memory(t_cub *cub);

/*
**	init_and_delete_1_bonus.c
*/

void			cub_load_texture_image_first_person(t_cub *cub);
void			cub_init_image_to_window_first_person(t_cub *cub);
int				cub_check_textures(t_cub *cub);
void			cub_force_exit(t_cub *cub);

/*
**	checkMap_0_bonus.c
*/

int				cub_check_map(t_map *map, char *file);

/*
**	checkMap_1_bonus.c
*/

int				cub_check_data_file(char *gnl);
int				cub_save_texture(t_map *map, char *gnl);
int				cub_check_texture_file(t_map *map);

/*
**	checkMap_2_bonus.c
*/
int				cub_save_map(t_map *map, char *gnl);
void			ft_set_color(t_cub *cub);
int				cub_init_map_var(t_map *map, char *file);
int				cub_read_map(t_map *map);

/*
**	checkmap_3_bonus.c
*/

void			cub_equal_line(t_map *map);
int				cub_first_last_line(char **map);
int				cub_rest_lines(char **map);

/*
**	checkMap_4_bonus.c
*/

int				cub_check_color(char *data);
void			cub_search_sprite_map(t_cub *cub);
char			*cub_detect_route(char *gnl);
void			cub_big_str_map(t_map *map);

/*
**	utilsCub_0.c
*/
int				ft_len_double_pointer(char **str);
void			free_double_p(char **str);
void			cub_remove_final_line(char *str);
char			*ft_free_and_save(char *str1, char *str2);
int				ft_n_maps_lines(char **map);

/*
**	define_params.c
*/
void			define_map_player(t_cub *cub);
void			define_player_vector(t_cub *cub);
void			define_cam(t_cub *cub);
void			define_actions(t_cub *cub);

/*
**	DDAalg_0_bonus.c
*/
void			ft_definepoint_dda(t_cub *cub);

/*
**	DDAalg_1_bonus.c
*/

void			ft_init_cam_ray(t_cub *cub, int x_coord);
void			ft_define_xy_size(t_cub *cub);
void			ft_step_and_lts(t_cub *cub);
void			ft_dda(t_cub *cub);
void			ft_vert_dim_wall(t_cub *cub, int x_coord);

/*
**	bresen_0_bonus.c
*/

void			ft_bresenham(int x_coord, t_cub *cub, int color);

/*
**	bresen_1_bonus.c
*/

unsigned int	ft_color(t_cub *cub, int y, int texture);
void			ft_define_disp_i(t_draw_line *data);
void			ft_define_disp_r(t_draw_line *data);
void			ft_define_adv(t_draw_line *data, int x1, int y1);
void			ft_define_type_adv(t_draw_line *data);

/*
**	utilsMov.c
*/
void			ft_move_forward(t_cub *cub);
void			ft_move_back(t_cub *cub);
void			ft_move_left(t_cub *cub);
void			ft_move_right(t_cub *cub);

/*
** utilsLook.c
*/

void			ft_look_left(t_cub *cub);
void			ft_look_right(t_cub *cub);
void			ft_look_mouse(t_cub *cub);

/*
**	ft_split_remake.c
*/

char			**ft_split_remake(char const *s, char c);

/*
**	sprite_player_bonus.c
*/

int				cub_animated_sprite_right_hand(t_cub *cub);
int				cub_animated_sprite_left_hand(t_cub *cub);
int				cub_animated_sprite_player_leg(t_cub *cub);

/*
**	ft_cub_bresen_s_bonus.c
*/

void			ft_bresenham_s(t_cub *cub, int x_coord, int texture);

/*
**	sprites_bonus.c
*/

void			ft_sprites(t_cub *cub);
void			cub_sprt_coord(t_cub *cub);
void			ft_init_sprites(t_cub *cub);

/*
**	mini_map_bonus.c
*/

void			ft_set_minimap(t_cub *cub);

/*
**	hook_game_0_bonus.c
*/

void			cub_delete_images(t_cub *cub);
void			cub_action(t_cub *cub);
void			cub_set_load_images(t_cub *cub);
void			cub_view_controls(t_cub *cub);

/*
**	hook_game_1_bonus.c
*/

void			cub_open_door(t_cub *cub, int *c);
void			cub_door_ctrl(t_cub *cub, int *c);

#endif