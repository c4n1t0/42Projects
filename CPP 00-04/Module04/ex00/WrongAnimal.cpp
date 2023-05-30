/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:04:26 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/11 23:32:38 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    this->type = "WrongAnimal";
    std::cout << "[WrongAnimal class] Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string _type)
{
    this->type = _type;
    std::cout << "[WrongAnimal class] Type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    *this = copy;
    std::cout << "[WrongAnimal class] Copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "[WrongAnimal class] Default desturctor called" << std::endl;
}

WrongAnimal&    WrongAnimal::operator=(const WrongAnimal &pointer)
{
    this->type = pointer.type;
    std::cout << "[WrongAnimal class] Assignation operator called" << std::endl;
    return (*this);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "[WrongAnimal class] makeSoung called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}
