/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:55:13 by jaromero          #+#    #+#             */
/*   Updated: 2023/03/16 00:33:55 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	{
		ClapTrap monster("Aurelio");
		ClapTrap killer("MonsterKill");

		monster.attack("All 42 persons!");
		monster.takeDamage(3);
		monster.beRepaired(1);
		monster = killer;
		killer.attack("jaromero");
		killer.takeDamage(9);
		killer.beRepaired(9);
        killer.attack("jaromero");
		return (0);
	}
}
