/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:05:49 by jaromero          #+#    #+#             */
/*   Updated: 2023/03/13 23:58:53 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string _name)
{
    this->name = _name;
    this->gun = NULL;
}

HumanB::~HumanB(void)
{
}

void    HumanB::attack(void)
{
    if (this->gun != NULL)
        std::cout << this->name << " attacks with their " << gun->getType() << std::endl;
    else
        std::cout << this->name << " attacks with their " << "leg and hands!!" << std::endl;
}

void    HumanB::setWeapon(Weapon &gun)
{
    this->gun = &gun;
}
