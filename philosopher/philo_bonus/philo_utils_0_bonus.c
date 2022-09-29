/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_0_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 00:51:28 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/29 23:33:50 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((*s1 == *s2) && *s1 != '\0' && *s2 != '\0' && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		s1--;
		s2--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_atoi(const char *nptr)
{
	int	signo;
	int	dev;

	signo = 1;
	dev = 0;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			signo = signo * -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		dev = dev * 10 + (*nptr - '0');
		nptr++;
	}
	dev = dev * signo;
	return (dev);
}

void	ft_free(t_time *time)
{
	sem_close(time->fork);
	sem_close(time->print);
	sem_unlink("forks");
	sem_unlink("print");
	free(time->n_eats);
	free(time->philosopher);
}

int	ft_get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}
