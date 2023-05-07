/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:46:58 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/01 23:48:38 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    leaks(void)
{
    system("leaks Zombie");
}

int main(void)
{
    std::string _name;
    std::string _name1;
    Zombie *zb1;

    std::cout << "Zombie created by Memory Stack!" << std::endl;
    std::cout << "Nombre del Zombie 1: ";
    std::getline(std::cin, _name);
    std::cout << "Zombie created by Memory HEAP!" << std::endl;
    std::cout << "Nombre del Zombie 2: ";
    std::getline(std::cin, _name1);
    randomChump(_name);
    zb1 = newZombie(_name1);
    zb1->announce();
    delete zb1;
    return (0);
}
