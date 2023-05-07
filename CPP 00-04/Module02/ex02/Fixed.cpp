/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:55:51 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/27 20:29:06 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
**  Constructores y destructores
*/

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

/*
**  Operadore de asignacion
*/

Fixed&  Fixed::operator=(const Fixed &pointer)
{
    std::cout << "Assignation operator called" << std::endl;
    this->value_point = pointer.getRawBits();
    return (*this);
}

/*
**  Metodos de la clase
*/

int Fixed::getRawBits( void ) const
{
    return (this->value_point);
}

void Fixed::setRawBits ( int const raw )
{
    this->value_point = raw;
}

const Fixed&   Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    else
        return (b);
}

Fixed&   Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    else
        return (b);
}

const Fixed&   Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    else
        return (b);
}

Fixed&   min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    else
        return (b);
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

/*
**  Operadores de comparacion
*/
bool   Fixed::operator>(Fixed temp) const
{
    return (this->getRawBits() > temp.getRawBits());
}

bool   Fixed::operator<(Fixed temp) const
{
    return (this->getRawBits() < temp.getRawBits());
}

bool   Fixed::operator>=(Fixed temp) const
{
    return (this->getRawBits() >= temp.getRawBits());
}

bool   Fixed::operator<=(Fixed temp) const
{
    return (this->getRawBits() <= temp.getRawBits());
}

bool   Fixed::operator==(Fixed temp) const
{
    return (this->getRawBits() == temp.getRawBits());
}

bool   Fixed::operator!=(Fixed temp) const
{
    return (this->getRawBits() != temp.getRawBits());
}

/*
**  Operadores aritmeticos
*/

Fixed   Fixed::operator+(Fixed temp) const
{
    Fixed   aux = *this;

    aux.setRawBits(aux.getRawBits() + temp.getRawBits());
    return (aux);
}

Fixed   Fixed::operator-(Fixed temp) const
{
    Fixed   aux = *this;

    aux.setRawBits(aux.getRawBits() - temp.getRawBits());
    return (aux);
}

Fixed  Fixed::operator*(Fixed temp) const
{
    Fixed   aux = *this;
    
    aux.setRawBits(aux.getRawBits() * temp.getRawBits() / (1 << fraction_bits));
    return (aux);
}

Fixed  Fixed::operator/(Fixed temp) const
{
    Fixed   aux = *this;
    aux.setRawBits(aux.getRawBits() * (1 << fraction_bits) / temp.getRawBits());
    return (aux);
}

/*
**  Operadores de preincremento y predecremento
*/

Fixed   Fixed::operator++(void)
{
    this->value_point++;
    return (*this);
}

Fixed   Fixed::operator--(void)
{
    this->value_point--;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   temp = *this;
    
    operator++();
    return (temp);
}

Fixed   Fixed::operator--(int)
{
    Fixed   temp = *this;
    
    operator--();
    return (temp);
}
