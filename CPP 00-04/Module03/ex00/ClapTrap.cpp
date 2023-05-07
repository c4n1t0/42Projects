/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:56:47 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/02 17:33:54 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->_name = "default";
    this->_hitPoints = 0;
    this->_energyPoints = 0;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "Name constructor called" << std::endl;
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Default destructor called" << std::endl;
}

ClapTrap&  ClapTrap::operator=(const ClapTrap &pointer)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_name = pointer._name;
    this->_hitPoints = pointer._hitPoints;
    this->_energyPoints = pointer._energyPoints;
    this->_attackDamage = pointer._attackDamage;
    return (*this);
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
        return ;
    }
    else if (this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " lost all energy points!!" << std::endl;
        return ;
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " Attacks " << target << ", causing "
            << this->_attackDamage << " points of damage!!" << std::endl;
        this->_energyPoints -= 1;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is dead!!" << std::endl;
        return ;
    }
    else
    {
        if (amount > this->_hitPoints)
            amount = this->_hitPoints;
        std::cout << "ClapTrap " << this->_name << " lost " << amount << " point of health" << std::endl; 
        this->_hitPoints -= amount;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
        return ;
    }
    else if (this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " lost all energy points!!" << std::endl;
        return ;
    }
    else
    {
        if (amount > this->_energyPoints)
            amount = this->_energyPoints;
        if (amount > (10 - this->_hitPoints))
            amount = (10 - this->_hitPoints);
        std::cout << "ClapTrap " << this->_name << " repair itself whith " << amount
            << " points, and his left HITPOINTS are " << (this->_hitPoints + amount) << std::endl;
        this->_hitPoints += amount;
        this->_energyPoints -= amount;
    }
}
