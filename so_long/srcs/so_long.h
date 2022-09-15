/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:51:52 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/04 00:52:58 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	int				*obs_x;
	int				*obs_y;
	int				*col_x;
	int				*col_y;
	int				*col_state;
	int				*player_state;
	int				*ext_x;
	int				*ext_y;
	int				len_obs;
	int				len_collect;
	int				len_exit;
	int				game_collect;
	int				door_state;
	mlx_t			*mlx;
	mlx_texture_t	*player;
	mlx_texture_t	*player_down;
	mlx_texture_t	*player_up;
	mlx_texture_t	*player_left;
	mlx_texture_t	*collect;
	mlx_texture_t	*exit;
	mlx_texture_t	*exit1;
	mlx_texture_t	*wall;
	mlx_image_t		*p_right;
	mlx_image_t		*p_down;
	mlx_image_t		*p_up;
	mlx_image_t		*p_left;
	mlx_image_t		*i_collect;
	mlx_image_t		*i_exit;
	mlx_image_t		*i_exit1;
	mlx_image_t		*i_wall;
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

void				ft_init_collect(t_imgdata *game, char **map);
void				ft_collect_in_len(t_imgdata *game, int lines, char **map);
void				ft_collect_in_block(t_imgdata *game, int lines, char **map);

void				ft_init_exit(t_imgdata *game, char **map);
void				ft_exit_in_len(t_imgdata *game, int lines, char **map);
void				ft_exit_in_block(t_imgdata *game, int lines, char **map);

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

#endif