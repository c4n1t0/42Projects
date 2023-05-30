/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:19:56 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/21 22:48:25 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
    std::cout << "[Cure class] default constructor called\n";
}

Cure::Cure(const Cure &copy)
{
    *this = copy;
    std::cout << "[Cure class] copy constructor called\n";
}

Cure::~Cure(void)
{
    std::cout << "[Cure class] default destructor called\n";
}

Cure&   Cure::operator=(const Cure &pointer)
{
    this->_type = pointer._type;
    std::cout << "[Cure class] asignation operator called\n";
    return (*this);
}

Cure*   Cure::clone(void) const
{
    std::cout << "[Cure class] clone a new object\n";
    return (new(Cure));
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}