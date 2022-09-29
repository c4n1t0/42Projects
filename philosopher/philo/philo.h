/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:48:04 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/26 13:49:28 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <fcntl.h>
# include <pthread.h>
# include <signal.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct philosopher
{
	int				p_id;
	int				left_fork;
	int				right_fork;
	int				die;
	int				eat;
	int				*run;
	int				init_time;
	struct time		*time;
	pthread_t		hilo;
}					t_philosopher;

typedef struct time
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_time_eat;
	int				*n_eats;
	int				run;
	int				arg;
	int				init_time;
	t_philosopher	*philosopher;
	pthread_t		death_line;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}					t_time;

void				ft_print(t_philosopher *philo, char *str);
void				ft_eat(t_philosopher *philo);
void				ft_sleep(t_philosopher *philo);
void				ft_death_or_alive(t_philosopher *philo);

void				*ft_cicle_of_life(t_philosopher *philo);
void				*ft_death_line(t_time *time);
int					ft_philo_loop(t_time *time, int i);

int					ft_argc_save(int len, char **argc, t_time *time, int i);
void				ft_init_philo(t_time *time);
void				ft_init_forks(t_time *time);
int					ft_compr_num(int argv, char **argc);

int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
void				ft_free(t_time *time);
int					ft_get_time(void);

#endif