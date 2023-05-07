/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:05:40 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/07 01:18:14 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &gun)
{
    this->name = _name;
    this->gun = &gun;
}

void    HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << gun->getType() << std::endl;
}

HumanA::~HumanA(void)
{
    
}
