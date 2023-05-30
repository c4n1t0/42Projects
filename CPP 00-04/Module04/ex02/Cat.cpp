/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:43:13 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/29 00:03:49 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
    std::cout << "[Cat Class] Default constructor called\n";
    this->ideas = new(Brain);
}

Cat::Cat(const Cat &copy)
{
    std::cout << "[Cat Class] Copy constructor called\n";
    this->ideas = new Brain(*copy.ideas);
    *this = copy;
}

Cat::~Cat(void)
{
    std::cout << "[Cat Class] Default destructor called\n";
    delete ideas;
}

Cat&    Cat::operator=(const Cat &pointer)
{
    std::cout << "[Cat class] Asignation operator called\n";
    if (this != &pointer)
    {
        this->type = pointer.type;
        delete this->ideas;
        this->ideas = new Brain (*pointer.ideas);
    }
    return (*this);
}

void    Cat::makeSound(void) const
{
    std::cout << "[Cat Class] The cat say Miaouuuuu!\n";
}
