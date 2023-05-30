/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:44:06 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/29 18:25:59 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	{
		ScavTrap monster("Aurelio");
		ScavTrap killer("MonsterKill");

		monster.attack("All 42 persons!");
		monster.takeDamage(20);
		monster.beRepaired(10);
		monster.attack("All 42 persons!");
		monster = killer;
		killer.attack("jaromero");
		killer.takeDamage(9);
		killer.beRepaired(9);
        killer.attack("jaromero");
		killer.guardGate();
		return (0);
	}
}
