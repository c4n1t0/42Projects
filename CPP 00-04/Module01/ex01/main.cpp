/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:01:55 by jaromero          #+#    #+#             */
/*   Updated: 2023/03/13 13:46:50 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <stdio.h>

void    leaks(void)
{
    system("leaks -q zombieHorde");
}

void zombie_Announce(Zombie *horde, int N)
{
    int i;

    i = 0;
    while (i < N)
    {
        horde[i].announce();
        i++;
    }
}

int main(void)
{
    Zombie      *hd;
    std::string _nick;
    int         num;

    std::cout << "Creating a new Horde of Zombie!" << std::endl;
    _nick = "Aureliooo";
    std::cout << "Nombre del Zombie: " << _nick << std::endl;
    num = 7;
    std::cout << "Tamaño de la Horda!: " << num << std::endl;
    if (num < 0 || num >= INT_MAX || num <= INT_MIN)
        return (atexit(leaks), 1);
    hd = zombieHorde(num, _nick);
    zombie_Announce(hd, num);
    delete[] hd;
    atexit(leaks);
    return (0);
}
