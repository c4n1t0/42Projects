/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:00:25 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/04 01:09:17 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    std::cout << "Name constructor called of // DiamondTrap //\n";
    this->_name = name;
    ClapTrap::_name = name + "_Clap_name";
    FragTrap::_hitPoints = 100;
    ScavTrap::_energyPoints = 50;
    FragTrap::_attackDamage = 30;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Default destructor // DiamondTrap // called" << std::endl;
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << "I`m " << _name << " a DiamondTrap, and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
