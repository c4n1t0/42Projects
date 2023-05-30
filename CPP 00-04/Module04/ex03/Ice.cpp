/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:22:58 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/21 23:19:37 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
    std::cout << "[Ice class] default constructor called\n";
}

Ice::Ice(const Ice &copy)
{
    *this = copy;
    std::cout << "[Ice class] copy constructor called\n";
}

Ice::~Ice(void)
{
    std::cout << "[Ice class] default destructor called\n";
}

Ice&    Ice::operator=(const Ice &pointer)
{
    this->_type = pointer._type;
    std::cout << "[Ice class] asignation operator called\n";
    return (*this); 
}

Ice*    Ice::clone(void) const
{
    std::cout << "[Ice class] clone a new object!\n";
    return (new(Ice));
}

void    Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
