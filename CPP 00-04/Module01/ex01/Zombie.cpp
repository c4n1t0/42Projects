/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:04:06 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/06 12:47:19 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(void)
{
}

void    Zombie::initZombie(std::string nick)
{
    this->name = nick;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie: " << name << "\t <------- Kill by HeadShot!" << std::endl;
}
