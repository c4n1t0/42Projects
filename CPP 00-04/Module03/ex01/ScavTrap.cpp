/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 00:54:21 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/02 17:31:43 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    std::cout << "Default constructor << ScavTrap >> called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Name constructor << ScavTrap >> called" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "Copy constructor << ScavTrap >> called" << std::endl;
    *this = copy;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "Default destructor << ScavTrap >> called" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "<< ScavTrap >> " << this->_name << " is dead!" << std::endl;
        return ;
    }
    else if (this->_energyPoints == 0)
    {
        std::cout << "<< ScavTrap >> " << this->_name << " lost all energy points!!" << std::endl;
        return ;
    }
    else
    {
        std::cout << "<< ScavTrap >> " << this->_name << " Attacks " << target << ", causing "
            << this->_attackDamage << " points of damage!!" << std::endl;
        this->_energyPoints -= 1;
    }
}

void    ScavTrap::guardGate(void)
{
    std::cout << "<< ScavTrap >> is now in Gate keeper mode." << std::endl;
}
