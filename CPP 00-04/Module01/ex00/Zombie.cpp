/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:51:23 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/01 23:53:57 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string  _name)
{
    this->name = _name;
}

Zombie::~Zombie(void)
{
    std::cout << "Zombie: " << name << "\t <------- Kill by HeadShot!" << std::endl;
}
