/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:06:54 by jaromero          #+#    #+#             */
/*   Updated: 2023/03/13 10:09:54 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main(void)
{
    if (bsp(Point(1, 1), Point(10, 10), Point(10, 0), Point(7, 3)) == true)
        std::cout << "Point is Allin!!" << std::endl;
    else 
        std::cout << "Point is Out!" << std::endl;
    return (0);
}
