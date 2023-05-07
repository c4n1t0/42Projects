/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:22:29 by jaromero          #+#    #+#             */
/*   Updated: 2023/03/01 21:00:33 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void    Harl::debug(void)
{   
    std::cout << "\n[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pick";
    std::cout << "lespecial-ketchup burger. \nI really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "\n[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. \nYou didn’t put";
    std::cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "\n[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. \nI’ve been coming";
    std::cout << "for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "\n[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string command[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i;

    i = 0;
    while (i < 4 && command[i].compare(level))
        i++;
    switch (i)
    {
        case    0:  debug();
        case    1:  info();
        case    2:  warning();
        case    3:  error();
            break;
        default:
            std::cout << "\n[ Probably complaining about insignificant problems ]\n" << std::endl;
    }
}
