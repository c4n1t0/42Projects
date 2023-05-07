/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:03:45 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/22 11:26:04 by jaromero         ###   ########.fr       */
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
        Fixed(void);
        Fixed(const int nbr);
        Fixed(const float nbr);
        Fixed(const Fixed &copy);
        ~Fixed(void);
        Fixed&  operator=(const Fixed &pointer);
        int     getRawBits( void ) const;
        void    setRawBits ( int const raw );
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream    &operator<<(std::ostream &out, const Fixed &pointer);

#endif