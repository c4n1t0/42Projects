/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:08:03 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/03 00:08:19 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    std::cout << "Default constructor || FragTrap || called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "Name constructor || FragTrap || called" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << "Copy constructor || FragTrap || called" << std::endl;
    *this = copy;
}

FragTrap::~FragTrap(void)
{
    std::cout << "Default destructor || FragTrap || called" << std::endl;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "High Five People!!" << std::endl;
}
