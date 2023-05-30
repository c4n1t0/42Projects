/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:42:43 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/08 01:04:59 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    this->type = "Animal";
    std::cout << "[Animal class] Default constructor called\n";
}

Animal::Animal(std::string _type)
{
    this->type = _type;
    std::cout << "[Animal class] Type constructor called\n";
}

Animal::Animal(const Animal &copy)
{
    *this = copy;
    std::cout << "[Animal class] Copy constructor called\n";
}

Animal::~Animal(void)
{
    std::cout << "[Animal class] Default destructor called\n";
}

Animal& Animal::operator=(const Animal &pointer)
{
    this->type = pointer.type;
    std::cout << "[Animal class] Assignation operator called\n";
    return (*this);
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void    Animal::makeSound(void) const
{
    std::cout << "[Animal Class] makeSound called\n";
}
