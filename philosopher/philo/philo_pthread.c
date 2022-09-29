/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:49:40 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/26 13:50:14 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_cicle_of_life(t_philosopher *philo)
{
	philo->init_time = philo->time->init_time;
	philo->eat = 0;
	philo->die = philo->time->t_die;
	if (philo->p_id % 2 == 0)
		usleep(500);
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
	}
	return (NULL);
}

void	*ft_death_line(t_time *time)
{
	int	i;
	int	philo_eats;

	i = 0;
	philo_eats = 0;
	usleep(1000);
	while (time->run)
	{
		while (i < time->n_philo)
		{
			ft_death_or_alive(&time->philosopher[i]);
			if (time->arg == 5)
			{
				if (time->n_eats[i] == time->n_time_eat)
					philo_eats++;
			}
			i++;
		}
		if (philo_eats >= time->n_philo)
			time->run = 0;
		philo_eats = 0;
		i = 0;
		usleep(1000);
	}
	return (NULL);
}

int	ft_philo_loop(t_time *time, int i)
{
	time->init_time = ft_get_time();
	while (++i < time->n_philo)
	{
		if (pthread_create(&time->philosopher[i].hilo, NULL,
				(void *)ft_cicle_of_life, &time->philosopher[i]) != 0)
			return (printf("Can't create thread"), -1);
		usleep(200);
	}
	if (pthread_create(&time->death_line, NULL, (void *)ft_death_line,
			time) != 0)
		return (printf("Can't create thread"), -1);
	while (time->run)
		usleep(1);
	return (0);
}
