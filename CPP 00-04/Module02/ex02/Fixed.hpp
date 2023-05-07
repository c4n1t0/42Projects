/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:56:23 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/27 20:29:52 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 value_point;
        static const int    fraction_bits = 8;
        
    public:
        // Constructores y destructores
        
        Fixed(void);
        Fixed(const int nbr);
        Fixed(const float nbr);
        Fixed(const Fixed &copy);
        ~Fixed(void);

        // Operador de asignacion
        Fixed&  operator=(const Fixed &pointer);

        // Operadores de comparacion
        bool   operator>(Fixed temp) const;
        bool   operator<(Fixed temp) const;
        bool   operator>=(Fixed temp) const;
        bool   operator<=(Fixed temp) const;
        bool   operator==(Fixed temp) const;
        bool   operator!=(Fixed temp) const;

        // Operadores artimeticos
        Fixed   operator+(Fixed temp) const;
        Fixed   operator-(Fixed temp) const;
        Fixed   operator*(Fixed temp) const;
        Fixed   operator/(Fixed temp) const;
        
        //Operadores preincremento y predecremento
        Fixed   operator++(void);
        Fixed   operator++(int);
        Fixed   operator--(void);
        Fixed   operator--(int);
        
        //Metodos de la clase

        int                 getRawBits( void ) const;
        void                setRawBits ( int const raw );
        float               toFloat(void) const;
        int                 toInt(void) const;
        
        static const Fixed& max(const Fixed &a, const Fixed &b);
        static Fixed&   max(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed&   min(Fixed &a, Fixed &b);
};

std::ostream    &operator<<(std::ostream &out, const Fixed &pointer);

#endif