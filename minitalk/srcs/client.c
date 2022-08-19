/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:37:41 by jaromero          #+#    #+#             */
/*   Updated: 2022/08/10 12:53:56 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	ft_send_bits(unsigned char octet, int pid_s)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		if (bit == '1')
		{
			if (kill(pid_s, SIGUSR2) == -1)
				return (ft_printf("\n\n--- Failed!! BAD PID SERVER!! ---\n\n"), -1);
		}
		else
		{
			if (kill(pid_s, SIGUSR1) == -1)
				return (ft_printf("\n\n--- Failed!! BAD PID SERVER!! ---\n\n"), -1);
		}
		usleep(100);
	}
	return (0);
}

void	receive(int signal)
{
	static int	received = 0;

	if (signal == SIGUSR2)
		++received;
	else
	{
		ft_printf("%d Bytes\n\n", received);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	const char	*str;

	str = argv[2];
	if (argc != 3 || ft_strlen(argv[2]) == 0)
	{
		ft_printf("\nExecution failed, incompatible arguments.\n\n");
		ft_printf("Please first argument PID-Server, ");
		return (ft_printf("second argument message.\n\n"), -1);
	}
	ft_printf("\nPID Client: %d\n\n", getpid());
	ft_printf("sending	:	%d Bytes\n\n", ft_strlen(argv[2]));
	ft_printf("receive	:	");
	signal(SIGUSR1, receive);
	signal(SIGUSR2, receive);
	while (str)
	{
		if (ft_send_bits(*str, ft_atoi(argv[1])) == -1)
			return (-1);
		str++;
	}
	while (1)
		pause();
	return (0);
}
