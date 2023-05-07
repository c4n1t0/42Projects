/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:39:22 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/03 00:00:14 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	FragTrap monster("Aurelio");
	FragTrap killer("MonsterKill");

	monster.attack("All 42 persons!");
	monster.takeDamage(20);
	monster.beRepaired(10);
	monster.attack("All 42 persons!");
	monster = killer;
	killer.attack("jaromero");
	killer.takeDamage(9);
	killer.beRepaired(1);
	killer.attack("jaromero");
	killer.highFivesGuys();
	return (0);
}
