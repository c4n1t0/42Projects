/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_save_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 00:06:37 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/26 11:51:46 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_argc_save(int len, char **argc, t_time *time, int i)
{
	while (i < len)
	{
		if (i == 1)
			time->n_philo = ft_atoi(argc[i]);
		if (i == 2)
			time->t_die = ft_atoi(argc[i]);
		if (i == 3)
			time->t_eat = ft_atoi(argc[i]);
		if (i == 4)
			time->t_sleep = ft_atoi(argc[i]);
		if (i == 5)
			time->n_time_eat = ft_atoi(argc[i]);
		i++;
	}
	if (i == 5)
	{
		time->arg = 4;
		time->n_time_eat = 0;
	}
	else
		time->arg = 5;
	if (time->n_philo < 1 || time->t_die < 0 || time->t_eat < 0
		|| time->t_sleep < 0 || time->n_time_eat < 0)
		return (-1);
	return (0);
}

void	ft_init_philo(t_time *time)
{
	int	i;

	i = -1;
	time->philosopher = malloc (sizeof(t_philosopher) * (time->n_philo + 1));
	time->n_eats = malloc (sizeof(int) * (time->n_philo + 1));
	while (++i < time->n_philo)
	{
		time->philosopher[i].p_id = i + 1;
		time->philosopher[i].run = &time->run;
		time->philosopher[i].time = time;
		time->n_eats[i] = 0;
		if (i == (time->n_philo - 1))
		{
			time->philosopher[i].left_fork = i + 1;
			time->philosopher[i].right_fork = 1;
		}
		else
		{
			time->philosopher[i].left_fork = i + 1;
			time->philosopher[i].right_fork = i + 2;
		}
	}
}

void	ft_init_forks(t_time *time)
{
	int	i;

	i = -1;
	time->fork = malloc(sizeof(pthread_mutex_t) * (time->n_philo + 1));
	while (++i < time->n_philo)
		pthread_mutex_init(&time->fork[i], NULL);
	pthread_mutex_init(&time->print, NULL);
}

int	ft_compr_num(int argv, char **argc)
{
	int	i;
	int	x;

	x = 0;
	i = 1;
	while (i < argv)
	{
		while (argc[i][x] != '\0')
		{
			if (argc[i][x] > '9' || argc[i][x] < '0')
				return (-1);
			x++;
		}
		x = 0;
		i++;
	}
	return (0);
}
