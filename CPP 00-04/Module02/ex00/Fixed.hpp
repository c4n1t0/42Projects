/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 00:52:21 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/21 00:55:41 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
    private:
        int                 value_point;
        static const int    fraction_bits = 8;
        
    public:
        Fixed(void);
        Fixed(Fixed &copy);
        ~Fixed(void);
        Fixed&  operator=(Fixed &pointer);
        int     getRawBits( void ) const;
        void    setRawBits ( int const raw ); 
};

#endif