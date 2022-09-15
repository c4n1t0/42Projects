/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:50:18 by jaromero          #+#    #+#             */
/*   Updated: 2022/09/14 11:33:11 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	int		lines;
	char	**map;

	if (argc != 2)
		return (ft_putstr_fd("Error\nInvalid arguments\n", 2), -1);
	if (ft_extension_check(argv[1]) == -1)
		return (ft_putstr_fd("Error\nInvalid extension map\n", 2), -1);
	lines = ft_count_line(argv[1]);
	if (lines < 3 && lines >= 0)
		return (ft_putstr_fd("Error\nInvalid map!!\n", 2), -1);
	if (lines == -1)
		return (ft_putstr_fd("Error\nFailed open map!!\n", 2), -1);
	map = ft_save_map(lines, argv[1]);
	if (ft_source_validator_map(map, lines) == -1)
		return (-1);
	ft_start_game(map, lines);
	return (0);
}
