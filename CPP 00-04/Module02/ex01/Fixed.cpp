/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:04:13 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/22 11:41:32 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->value_point = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr)
{
    this->value_point = nbr << fraction_bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nbr)
{
    this->value_point = roundf(nbr * (1 << fraction_bits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
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
    return (this->value_point);
}

void Fixed::setRawBits ( int const raw )
{
    this->value_point = raw;
}

Fixed&  Fixed::operator=(const Fixed &pointer)
{
    std::cout << "Assignation operator called" << std::endl;
    this->value_point = pointer.getRawBits();
    return (*this);
}

float   Fixed::toFloat(void) const
{
    return ((float)value_point / (1 << fraction_bits));
}

int     Fixed::toInt(void) const
{
    return (value_point >> fraction_bits);
}

std::ostream    &operator<<(std::ostream &out, const Fixed &pointer)
{
    out << pointer.toFloat();
    
    return (out);
}