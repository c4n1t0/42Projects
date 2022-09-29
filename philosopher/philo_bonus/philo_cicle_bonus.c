/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cicle_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:43:11 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/26 11:20:09 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print(t_philosopher *philo, char *str)
{
	sem_wait(philo->time->print);
	if (ft_strncmp(str, "eating", 20) == 0)
		printf("%d %d is eating\n", (ft_get_time() - philo->time->init_time),
			philo->p_id);
	else if (ft_strncmp(str, "take a fork", 20) == 0)
		printf("%d %d has taken a fork\n", (ft_get_time()
				- philo->time->init_time), philo->p_id);
	else if (ft_strncmp(str, "sleep", 20) == 0)
		printf("%d %d is sleeping\n", (ft_get_time() - philo->time->init_time),
			philo->p_id);
	else if (ft_strncmp(str, "think", 20) == 0)
		printf("%d %d is thinking\n", (ft_get_time() - philo->time->init_time),
			philo->p_id);
	else if (ft_strncmp(str, "died", 20) == 0)
	{
		printf("%d %d died\n", (ft_get_time() - philo->time->init_time),
			philo->p_id);
		*philo->run = 0;
		exit(1);
	}
	sem_post(philo->time->print);
}

void	ft_eat(t_philosopher *philo)
{
	sem_wait(philo->time->fork);
	ft_print(philo, "take a fork");
	sem_wait(philo->time->fork);
	ft_print(philo, "take a fork");
	ft_print(philo, "eating");
	philo->time->n_eats[philo->p_id - 1] += 1;
	philo->eat = ft_get_time() - philo->time->init_time;
	philo->die = (ft_get_time() - philo->time->init_time) + philo->time->t_die;
	while (ft_get_time() - philo->time->init_time != philo->eat
		+ philo->time->t_eat)
		usleep(500);
	sem_post(philo->time->fork);
	sem_post(philo->time->fork);
}

void	ft_sleep(t_philosopher *philo)
{
	int	sleep;

	sleep = ft_get_time();
	ft_print(philo, "sleep");
	while (ft_get_time() - philo->time->init_time != ((sleep
				- philo->time->init_time) + philo->time->t_sleep))
		usleep(500);
	ft_print(philo, "think");
}

void	ft_death_or_alive(t_philosopher *philo)
{
	if (philo->time->arg == 5)
	{
		if (philo->time->n_eats[philo->p_id - 1] < philo->time->n_time_eat)
		{
			if ((ft_get_time() - philo->time->init_time) > (philo->die))
				ft_print(philo, "died");
		}
	}
	else
	{
		if ((ft_get_time() - philo->time->init_time) > (philo->die))
			ft_print(philo, "died");
	}
}
