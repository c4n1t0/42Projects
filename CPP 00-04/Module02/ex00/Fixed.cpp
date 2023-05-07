/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:53:26 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/21 00:55:48 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->value_point = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value_point);
}

void Fixed::setRawBits ( int const raw )
{
    this->value_point = raw;
}

Fixed&  Fixed::operator=(Fixed &pointer)
{
    std::cout << "Assignation operator called" << std::endl;
    this->value_point = pointer.getRawBits();
    return (*this);
}
