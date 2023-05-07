/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:53:42 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/27 20:18:48 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
    }
    std::cout << "\nPress enter to continue..." << std::endl;
    system("read");
    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) );
        Fixed c (2.52344f);

        std::cout << a << std::endl;
        std::cout << --a << std::endl;
        std::cout << a << std::endl;
        std::cout << a-- << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
        std::cout << "c = " << c << std::endl;
        std::cout << "a + b " << a + b << std::endl;
        std::cout << "a - b " << a - b << std::endl;
        std::cout << "Max a y b " << Fixed::max( a, b ) << std::endl;
        std::cout << "Min a y b " << Fixed::min( a, b ) << std::endl;
        std::cout << "a > b " << (a > b) << std::endl;
        std::cout << "a < b " << (a < b) << std::endl;
        std::cout << "c >= b " << (c >= b) << std::endl;
        std::cout << "c <= b " << (c <= b) << std::endl;
        std::cout << "c == b " << (c == b) << std::endl;
        std::cout << "c != b " << (c != b) << std::endl;
    }
    return (0);
}