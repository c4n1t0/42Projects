/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:09:06 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/21 22:58:42 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
    this->_type = "VOID";
    std::cout << "[AMateria class] default constructor called\n";
}

AMateria::AMateria(std::string const &type)
{
    this->_type = type;
    std::cout << "[AMateria class] type constructor called\n";
}

AMateria::AMateria(AMateria const &copy)
{
    *this = copy;
    std::cout << "[AMateria class] copy constructor called\n";
}

AMateria::~AMateria(void)
{
    std::cout << "[AMateria class] default destructor called\n";
}

AMateria&   AMateria::operator=(AMateria const &pointer)
{
    this->_type = pointer._type;
    std::cout << "[AMateria class] asignation operator called\n";
    return (*this);
}

std::string const&  AMateria::getType(void) const
{
    return (this->_type);
}

void    AMateria::use(ICharacter& target)
{
    std::cout << "[AMateria class] " << this->_type << " used on " << target.getName() << std::endl;
}
