/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:51:52 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/12 17:33:23 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

# define TITLE "##### The So_Long!! #####"

struct				s_map
{
	int				c;
	int				e;
	int				p;
	int				i;
	int				x;
};

typedef struct image_data
{
	int				width;
	int				height;
	int				counter;
	int				y_axis;
	int				x_axis;
	int				*e_y_axis;
	int				*e_x_axis;
	int				*enemy_loop;
	int				*obs_x;
	int				*obs_y;
	int				*col_x;
	int				*col_y;
	int				*col_state;
	int				*player_state;
	int				*enemy_state_up;
	int				*enemy_state_down;
	int				*enemy_state_left;
	int				*enemy_state_right;
	int				*enemy_xy;
	int				*ext_x;
	int				*ext_y;
	int				len_obs;
	int				len_collect;
	int				len_exit;
	int				*len_enemy;
	int				init_enemy;
	int				game_collect;
	int				door_state;
	char			*str;
	mlx_t			*mlx;
	mlx_texture_t	*player;
	mlx_texture_t	*player_down;
	mlx_texture_t	*player_up;
	mlx_texture_t	*player_left;
	mlx_texture_t	*enemy_up;
	mlx_texture_t	*enemy_down;
	mlx_texture_t	*enemy_left;
	mlx_texture_t	*enemy_right;
	mlx_texture_t	*collect_0;
	mlx_texture_t	*collect_1;
	mlx_texture_t	*collect_2;
	mlx_texture_t	*collect_3;
	mlx_texture_t	*collect_4;
	mlx_texture_t	*collect_5;
	mlx_texture_t	*collect_6;
	mlx_texture_t	*collect_7;
	mlx_texture_t	*collect_8;
	mlx_texture_t	*collect_9;
	mlx_texture_t	*exit;
	mlx_texture_t	*exit1;
	mlx_texture_t	*wall;
	mlx_image_t		*p_right;
	mlx_image_t		*p_down;
	mlx_image_t		*p_up;
	mlx_image_t		*p_left;
	mlx_image_t		*e_up;
	mlx_image_t		*e_down;
	mlx_image_t		*e_right;
	mlx_image_t		*e_left;
	mlx_image_t		*i_collect_0;
	mlx_image_t		*i_collect_1;
	mlx_image_t		*i_collect_2;
	mlx_image_t		*i_collect_3;
	mlx_image_t		*i_collect_4;
	mlx_image_t		*i_collect_5;
	mlx_image_t		*i_collect_6;
	mlx_image_t		*i_collect_7;
	mlx_image_t		*i_collect_8;
	mlx_image_t		*i_collect_9;
	mlx_image_t		*i_exit;
	mlx_image_t		*i_exit1;
	mlx_image_t		*i_wall;
	mlx_image_t		*i_count;
	mlx_image_t		*i_count1;
}					t_imgdata;

int					ft_extension_check(char *str);
int					ft_count_line(char *root);
char				**ft_save_map(int lines, char *root);

int					ft_len_map(char **map, int lines);
int					ft_wall_up(char **map);
int					ft_wall_down(char **map, int lines);
int					ft_wall_detector(char **map, int lines);
int					ft_wall_left_right(char **map, int lines);

int					ft_validator_empty_space(char **map, int lines);
int					ft_initial_case_validator(char **map, int lines);
int					ft_source_validator_map(char **map, int lines);

void				ft_start_game(char **map, int lines);

void				ft_wall_in_len(t_imgdata *game, int lines, char **map);
void				ft_wall_in_block(t_imgdata *game, int lines, char **map);
void				ft_init_wall(t_imgdata *game, char **map);
void				ft_texture_player(t_imgdata *game, int x, int y);
void				ft_init_player(t_imgdata *game, char **map);

void				ft_collect_in_len(t_imgdata *game, int lines, char **map);
void				ft_collect_in_block(t_imgdata *game, int lines, char **map);
void				ft_init_sprite(t_imgdata *game);
void				ft_sprite_to_windows(t_imgdata *game, int i, int x, int y);
void				ft_init_collect(t_imgdata *game, char **map);

void				ft_init_exit(t_imgdata *game, char **map);
void				ft_exit_in_len(t_imgdata *game, int lines, char **map);
void				ft_exit_in_block(t_imgdata *game, int lines, char **map);
void				ft_init_strings(t_imgdata *game);

int					ft_wall_w(t_imgdata *const data2);
int					ft_wall_s(t_imgdata *const data2);
int					ft_wall_a(t_imgdata *const data2);
int					ft_wall_d(t_imgdata *const data2);

void				ft_collect_game_w(t_imgdata *data2);
void				ft_collect_game_s(t_imgdata *data2);
void				ft_collect_game_a(t_imgdata *data2);
void				ft_collect_game_d(t_imgdata *data2);

int					ft_exit_game_w(t_imgdata *data2);
int					ft_exit_game_s(t_imgdata *data2);
int					ft_exit_game_a(t_imgdata *data2);
int					ft_exit_game_d(t_imgdata *data2);

void				free_map(char **p);
int					ft_check_col(t_imgdata *data2);
void				ft_open_door(t_imgdata *data2);
void				ft_init_col_state(t_imgdata *game);
void				ft_size_windows(t_imgdata *game, char **map);

void				ft_position_player_up(t_imgdata *data2);
void				ft_position_player_down(t_imgdata *data2);
void				ft_position_player_left(t_imgdata *data2);
void				ft_position_player_right(t_imgdata *data2);

void				ft_end_game(t_imgdata *data2);
void				ft_del_texture(t_imgdata *game);
void				ft_free_pointers(t_imgdata *game, char **map);

void				ft_key_up(t_imgdata *data2);
void				ft_key_down(t_imgdata *data2);
void				ft_key_right(t_imgdata *data2);
void				ft_key_left(t_imgdata *data2);
void				ft_finish_comp(t_imgdata *data2);

void				ft_enemy_in_len(t_imgdata *game, int lines, char **map);
void				ft_load_enemy(t_imgdata *game);
void				ft_put_enemy(t_imgdata *game, int x, int y, char **map);
void				ft_init_enemy(t_imgdata *game, char **map);

void				ft_enemy_hooks_up(t_imgdata *data2, int i);
void				ft_enemy_hooks_down(t_imgdata *data2, int i);
void				ft_enemy_hooks_right(t_imgdata *data2, int i);
void				ft_enemy_hooks_left(t_imgdata *data2, int i);
void				ft_enemy_hooks(t_imgdata *data2);

int					ft_wall_w_enemy(t_imgdata *const data2, int x);
int					ft_wall_s_enemy(t_imgdata *const data2, int x);
int					ft_wall_a_enemy(t_imgdata *const data2, int x);
int					ft_wall_d_enemy(t_imgdata *const data2, int x);

int					ft_enemy_w(t_imgdata *const data2);
int					ft_enemy_s(t_imgdata *const data2);
int					ft_enemy_a(t_imgdata *const data2);
int					ft_enemy_d(t_imgdata *const data2);

void				ft_sub1_col_sprite(t_imgdata *data2, int i, int y);
void				ft_sub2_col_sprite(t_imgdata *data2, int i, int y);

#endif