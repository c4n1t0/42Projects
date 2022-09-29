/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pthread_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:49:40 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/29 12:45:20 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_cicle_of_life(t_philosopher *philo)
{
	philo->eat = 0;
	philo->die = philo->time->t_die;
	if (philo->p_id % 2 == 0)
		usleep(500);
	pthread_create(&philo->time->death_line, NULL, (void *)ft_death_line,
		philo);
	if (philo->time->arg == 4)
	{
		while (*philo->run)
		{
			ft_eat(philo);
			ft_sleep(philo);
		}
	}
	else if (philo->time->arg == 5)
	{
		while (*philo->run && philo->time->n_eats[philo->p_id
				- 1] < philo->time->n_time_eat)
		{
			ft_eat(philo);
			if (*philo->run)
				ft_sleep(philo);
		}
		exit(0);
	}
}

void	ft_death_line(t_philosopher *philo)
{
	usleep(1000);
	while (*philo->run)
	{
		ft_death_or_alive(philo);
		if (philo->time->arg == 5)
		{
			if (philo->time->n_eats[philo->p_id - 1] == philo->time->n_time_eat)
				*philo->run = 0;
		}
		usleep(1000);
	}
}

void	ft_philo_loop_wait(t_time *time)
{
	int	died;
	int	status;
	int	i;

	i = -1;
	died = 0;
	while (++i < time->n_philo && died == 0)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < time->n_philo)
				kill(time->philosopher[i].pid, SIGTERM);
			died = 1;
		}
	}
}

int	ft_philo_loop(t_time *time)
{
	int				i;
	t_philosopher	*phil;

	phil = time->philosopher;
	time->init_time = ft_get_time();
	i = -1;
	while (++i < time->n_philo)
	{
		phil[i].pid = fork();
		if (phil[i].pid == 0)
			ft_cicle_of_life(&(phil[i]));
		if (phil[i].pid < 0)
			return (printf("\nCan't create the process\n"), -1);
		usleep(20);
	}
	ft_philo_loop_wait(time);
	return (0);
}
