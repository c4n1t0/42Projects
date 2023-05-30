/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:35:03 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/29 00:04:29 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "[Dog Class] Default constructor called\n";
    this->ideas = new Brain;
}

Dog::Dog(const Dog &copy)
{
    std::cout << "[Dog Class] Copy constructor called\n";
    this->ideas = new Brain (*copy.ideas);
    *this = copy;
}

Dog::~Dog(void)
{
    std::cout << "[Dog Class] Default destructor called\n";
    delete ideas;
}

Dog&    Dog::operator=(const Dog &pointer)
{
    std::cout << "[Dog class] Asignation operator called\n";
    if (this != &pointer)
    {
        this->type = pointer.type;
        delete this->ideas;
        this->ideas = new Brain (*pointer.ideas);
    }
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "[Dog Class] The dog say GUAU GUAU!\n";
}
