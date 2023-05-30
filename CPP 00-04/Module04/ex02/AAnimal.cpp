/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:42:43 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/15 12:45:54 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
    this->type = "AAnimal";
    std::cout << "[AAnimal class] Default constructor called\n";
}

AAnimal::AAnimal(std::string _type)
{
    this->type = _type;
    std::cout << "[AAnimal class] Type constructor called\n";
}

AAnimal::AAnimal(const AAnimal &copy)
{
    *this = copy;
    std::cout << "[AAnimal class] Copy constructor called\n";
}

AAnimal::~AAnimal(void)
{
    std::cout << "[AAnimal class] Default destructor called\n";
}

AAnimal& AAnimal::operator=(const AAnimal &pointer)
{
    this->type = pointer.type;
    std::cout << "[AAnimal class] Assignation operator called\n";
    return (*this);
}

std::string AAnimal::getType(void) const
{
    return (this->type);
}

void    AAnimal::makeSound(void) const
{
    std::cout << "[AAnimal Class] makeSound called\n";
}
