/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:05:57 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/14 17:58:55 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string data)
{
    if (data.compare("") == 0)
        this->type = "leg and hands!!";
    else
        this->type = data;
}

Weapon::~Weapon(void)
{
    
}

std::string&    Weapon::getType(void)
{
    return (this->type);
}

void    Weapon::setType(std::string _type)
{
    if (_type.compare("") == 0)
        this->type = "leg and hands!!";
    else
        this->type = _type;
}