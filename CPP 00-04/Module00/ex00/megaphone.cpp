/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 00:01:18 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/14 18:12:11 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int     ft_content_alpha(char *entry)
{
    int i;

    i = 0;
    while (entry[i] != '\0')
    {
        if (isprint(entry[i]))
            return (0);
        i++;
    }
    return (1);
}

int ft_check_args(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (argv[i] && ft_content_alpha(argv[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}

void	ft_megaphone(int argc, char **argv)
{
	char	*p;
	int		i;

	i = 1;
	p = argv[i];
	while (i < argc)
	{
		if (*p != '\0')
		{
			if (*p == -61)
			{
				std::cout << "Ñ";
				p++;
			}
			else
				std::cout << (char)toupper(*p);
			p++;
		}
		if (*p == '\0')
		{
			i++;
			if (argv[i])
				p = argv[i];
		}
	}
    std::cout << "\n";
}

int	main(int argc, char **argv)
{
	if (argc < 2 || ft_check_args(argc, argv) == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (-1);
	}
	else
        ft_megaphone(argc, argv);
	return (0);
}
