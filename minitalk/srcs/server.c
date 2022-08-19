/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:29:54 by jaromero          #+#    #+#             */
/*   Updated: 2022/08/08 14:27:26 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static void	ft_receive(int signal, siginfo_t *info, void *context)
{
	static int				x = 7;
	static unsigned char	str = 0;
	static pid_t			client_pid = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (signal == SIGUSR2)
		str = (1 << x) | str;
	x--;
	if (x < 0)
	{
		if (str == '\0')
		{
			kill(client_pid, SIGUSR1);
			x = 7;
			client_pid = 0;
			ft_printf("\n");
			return ;
		}
		ft_printf("%c", str);
		kill(client_pid, SIGUSR2);
		x = 7;
		str = 0;
	}
}

void	poweroff(int signal)
{
	ft_printf("\n\n------ The server is shooting Down!! ------\n\n Bye Bye!!\n\n");
	signal = 0;
	usleep(1500000);
	system("clear screen");
	exit(signal);
}

int	main(int argc, char **argv)
{
	struct sigaction	data;

	system("clear screen");
	argv[1] = NULL;
	if (argc != 1)
	{
		ft_printf("\nExecution failed. Arguments must be 0!!\n\n");
		return (-1);
	}
	ft_printf("\nSERVER PID = %d\n\n", getpid());
	data.sa_sigaction = ft_receive;
	data.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &data, 0);
	sigaction(SIGUSR2, &data, 0);
	signal(SIGINT, poweroff);
	while (1)
		pause();
	return (0);
}
