/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:46:54 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/26 11:54:47 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argv, char **argc)
{
	t_time	time;
	int		i;

	i = 0;
	if (argv < 5 || argv > 6)
		return (write(2, "Error\n", 6), -1);
	if (ft_compr_num(argv, argc) == -1)
		return (write(2, "Error\n", 6), -1);
	if (ft_argc_save(argv, argc, &time, i) == -1)
		return (write(2, "Error\n", 6), -1);
	ft_init_philo(&time);
	ft_init_forks(&time);
	time.run = 1;
	if (ft_philo_loop(&time) == -1)
		return (ft_free(&time), -1);
	ft_free(&time);
	return (0);
}
