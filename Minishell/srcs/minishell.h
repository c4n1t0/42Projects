/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 10:38:46 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/27 20:05:19 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <dirent.h>
# include <pthread.h>
# include <errno.h>
# include <sys/stat.h>
# include <readline/history.h>
# include <readline/readline.h>

/*
**	Definición de tamaño máximo de buffer
**	para los PATH
*/
# define MAX_B 200

typedef struct s_ms_data
{
	char		act_path[MAX_B];
	char		*act_folder;
	char		*v_exit;
	char		*outfile;
	char		*infile;
	char		**envp;
	char		*gnl;
	int			ext;
	int			sys_path;
	int			no_sys_path;
	int			status_path;
	int			n_f;
	int			red;
	int			fd_blt;
	int			fd_in;
	int			redirection_status;
	int			pipe;
	int			signal;
	int			status_sig;
	pid_t		pid_pr;
}				t_ms_data;

typedef struct s_command
{
	char		*infile;
	char		*comnd;
	int			size;
}				t_command;

typedef struct s_quote
{
	char		*p;
	int			i;
}				t_quote;

typedef struct s_rm_quote
{
	char	*p;
	char	*q;
	char	*str;
}			t_rm_quote;

typedef struct s_change_var
{
	char	*p;
	char	*q;
	char	*str;
	int		i;
	int		status;
}			t_change_var;

typedef struct s_redirect
{
	char	*p;
	char	*q;
	int		i;
	int		mode;
}			t_redirect;

typedef struct s_wld_data
{
	char	**p;
	char	*q;
	char	**wld;
	char	*wld_aux;
	int		*wld_mode;	
}			t_wld_data;

typedef struct s_aux_check
{
	char	*temp_gnl;
	char	**split_gnl;
	int		pos;
}			t_aux_check;

typedef struct s_sv_envp
{
	int		i;
	int		shlvl;
	int		x;
}			t_sv_envp;

typedef struct s_get_path
{
	char	**all_paths;
	char	*cmd_path;
	int		i;
}			t_get_path;

typedef struct s_pipes_var
{
	char	*str;
	char	*p;
	int		i;
}			t_pipes_var;

/*
**	Variable Global para estructura de datos
*/

t_ms_data		*g_ms_data;

/*
**  main.c
*/
int				ft_builtins(char **split, t_ms_data *ms_data);

/*
**	analytics.c
*/
void			ft_analytics(char *gnl, t_ms_data *ms_data);

/*
**  utils_0.c
*/
void			free_split(char **p);
void			ft_putstr_mod(char *s, int fd);
void			ft_print_env(char **envp, t_ms_data *s_ms_data);
char			*ft_delete_spaces(char *gnl);

/*
**  utils_1.c
*/
void			ft_free_double_p(char **str);
int				ft_strchr_int(char *str, char c);
char			*ft_check_path(char **all_paths, char *cmd);
int				ft_array_size(char **split);
char			*ft_only_check_path(char *all_paths, char *cmd);

/*
**	utils_2.c
*/
char			*ft_strchr_var(const char *s, int c);
char			*ft_strchr_pipes(const char *s, int c);
char			**ft_split_pipe(char const *s, char c);

/*
**	utils_3.c
*/
char			*ft_free_and_join(char *instr, char *str);
void			ft_delay_exec(void);
int				ft_check_gnl(char *gnl);
char			*ft_delete_isspaces(char *str);
char			**ft_free_and_split_pipe(char **split, char *gnl);

/*
**  ft_echo_0.c
*/
void			ft_echo_option_n(char **split, char **envp, int fd);
void			ft_echo_standard(char **split, char **envp, int fd);
void			ft_echo(char **split, char **envp, t_ms_data *ms_data);

/*
**	directory.c
*/
void			ft_cd(t_ms_data *ms_data, char *new_path);
void			ft_pwd(t_ms_data *ms_data);
char			*ft_home(void);
void			ft_act_folder(t_ms_data *ms_data);

/*
**	signals.c
*/
void			ft_act_signals(int signal);
void			ft_signal_cmd(int exit, t_ms_data *ms_data);

/*
**	ft_exec_comd.c
*/
char			*ft_get_path(char **envp, char *cmd, t_ms_data *ms_data);
int				ft_print_error_access(char	*cmd, char *path,
					t_ms_data *ms_data);
void			ft_ex_cmd(char *cmd, char **envp, t_ms_data *ms_data);

/*
**	ft_error_exec.c
*/
void			ft_error_permission(char *cmd);
void			ft_error_directory(char *cmd);
void			ft_error_file(char *cmd);
void			ft_error_cmd(char *cmd);
void			ft_error_fork(t_ms_data *ms_data);

/*
**	exc_rest.c
*/
void			ft_exc_rest(char *gnl, char **envp, t_ms_data *ms_data);

/*
**	pipex_0.c
*/
void			ft_p_ex_cmd(char *cmd, char **envp, t_ms_data *ms_data);
int				pipex(int argc, char **argv, char **envp, t_ms_data *ms_data);
void			ft_get_name(char **first_sent, t_command *command);
int				ft_open_f(char *filename, int t_file, t_ms_data *ms_data);
void			ft_pipe(char *cmd, char **envp, int fd, t_ms_data *ms_data);

/*
**	pipex_1.c
*/
void			ft_pipes(char **split, char **envp, t_ms_data *ms_data);

/*
**	export_0.c
*/
char			*ft_free_and_save(char *str, char *envp);
char			**ft_sub_export_exec(char *str);
void			ft_export_exec(char *str);
int				ft_export_source(char **split, int i, t_ms_data *ms_data);
void			ft_export(char **split, t_ms_data *ms_data);

/*
**	export_1.c
*/
void			ft_export_print_error(char **split, int i);
char			*ft_export_sub_print_envp(char *p, int fd);
void			ft_export_print_envp(t_ms_data *ms_data);
int				ft_validation_var(char *str);

/*
**	unset.c
*/
char			**ft_sub_unset(char **aux, char **envp, char **split, int x);
char			**ft_unset_var(char **split, int x, char **envp);
int				ft_check_var(char *split);
char			**ft_unset(char **split, char **envp, t_ms_data *ms_data);

/*
**	var_env_0.c
*/
char			*ft_search_var_env_init(char *p);
char			*ft_subchange_var(char *gnl, t_ms_data *ms_data);
char			*ft_delete_var(char	*gnl);
char			*ft_change_var(char *gnl, t_ms_data *ms_data);

/*
**	var_env_1.c
*/
char			*ft_change_lvl(char *str);
void			ft_save_envp_global(char **envpi);
void			ft_change_last_exec(char *str, t_ms_data *ms_data, int pipe);

/*
**	ft_exit.c
*/
void			ft_force_exit(char *str, char **split);
void			ft_max_llong(char *str, char **split);
void			ft_analytics_exit(char *str, char **split);
long long int	ft_delete_cero(char *str, char **split);
void			ft_exit(char **split, t_ms_data *ms_data);

/*
**	quote_0.c
*/
char			*ft_remove_quote(char *split);
char			**ft_parse_quote(char **split);

/*
**	quote_1.c
*/
int				ft_quote_pipe(char *str, char *s);

/*
**	infile_and_outfile.c
*/
void			ft_outfile_arg(char *gnl, t_ms_data *ms_data);
void			ft_pipe2(char *cmd, char **envp, int fd, t_ms_data *ms_data);
void			ft_infile_arg(char *gnl, t_ms_data *ms_data);
void			ft_inoutfile_arg(char **split, t_ms_data *ms_data);

/*
**	check_pipe.c
*/
int				ft_check_pipes(char *gnl, t_ms_data *ms_data);

/*
**	redirections_out.c
*/
void			ft_redirection_error_out(int i, int nbr, t_ms_data *ms_data);
int				ft_check_redirection_out(char *p, t_ms_data *ms_data);
void			ft_init_redirect_value(t_redirect *redir, t_ms_data *ms_data,
					char *gnl, char c);
void			ft_save_redirect_file(t_redirect *redir, t_ms_data *ms_data,
					char *gnl);
char			*ft_remove_redirection_out(char *gnl, t_ms_data *ms_data);

/*
**	redirections_in_0.c
*/
char			*ft_remove_redirection_in(char *gnl, t_ms_data *ms_data);

/*
**	redirections_in_1.c
*/
int				ft_open_infile(char *filename, t_ms_data *ms_data);
void			ft_redirection_error_in(int i, int nbr, t_ms_data *ms_data);
int				ft_check_redirection_in(char *p, t_ms_data *ms_data);
void			ft_infile_double_redirection(t_ms_data *ms_data, char *gnl);
void			ft_prepare_dred_in(char *gnl, t_ms_data *ms_data);
int				ft_chk_red_pipe(char *p);

/*
**	redirections_in_2.c
*/
void			ft_init_value_redirection(t_ms_data *ms_data);
void			ft_dred_file_dup(char *aux, char *str);
char			*ft_dred_file(char *gnl, t_ms_data *ms_data);
int				ft_detec_dr(char *gnl);
int				ft_heredoc_pipe(t_ms_data *ms_data, char *gnl);

/*
**	redirections_in_3.c
*/
int				ft_chk_red_pipe(char *p);
void			ft_while_redir(char *p, t_ms_data *ms_data);
int				ft_check_redirection_in(char *p, t_ms_data *ms_data);
void			ft_infile_triple_redirection(char *str, t_ms_data *ms_data);

/*
**	redirection_prepare.c
*/
void			ft_redirecions_exec(t_ms_data *ms_data, char **split,
					char *gnl);
char			*ft_loop_redirc_out(char *gnl, t_ms_data *ms_data);
char			*ft_loop_redirc_in(char *gnl, t_ms_data *ms_data);
char			*ft_redirections_prepare(char *gnl, t_ms_data *ms_data);

/*
**	wildcards.c
*/
char			*ft_change_wildcard(char *gnl);

/*
**	wildcards_utils_1.c
*/
char			*ft_n_punt(char *d_name, int size_wld);
char			*ft_newstrchr(char *p, int c);
int				ft_n_wld(char *target);
int				ft_checktype3(char *wld, char *d_name);
int				ft_checktype4(char *wld, char *d_name);

/*
**	wildcards_utils_2.c
*/
char			*ft_wld_strjoin(char *s1, char *s2);
int				ft_check_wld(char **d_wld, char *d_name);
char			*ft_strstr(char *str, char *to_find);

/*
**	wildcards_utils_3.c
*/
char			*ft_checkdir(char **wld, char *gnl, int *wld_mode, char **p);

void			ft_leaks(void);
int				ft_check_gnl(char *gnl);

#endif