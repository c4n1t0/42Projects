/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:31:47 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/26 19:06:07 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argv, char **argc)
{
    if (argv != 2)
    {
        if (argv < 2)
            std::cerr << "Need some data to convert!" << std::endl;
        if (argv > 2)
            std::cerr << "Too many data to convert!" << std::endl;
        return (1);
    }
    {
        ScalarConverter asdf(argc[1]);        
    }
    return (0);
}