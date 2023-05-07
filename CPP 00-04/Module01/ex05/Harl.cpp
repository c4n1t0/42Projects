/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:02:25 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/16 13:08:46 by jaromero         ###   ########.fr       */
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
    std::cout << "\nI love having extra bacon for my 7XL-double-cheese-triple-pick";
    std::cout << "lespecial-ketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "\nI cannot believe adding extra bacon costs more money. You didn’t put";
    std::cout << "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "\nI think I deserve to have some extra bacon for free. I’ve been coming";
    std::cout << "for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    function harls[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string command[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i;

    i = 0;
    while (command[i].compare(level))
        i++;
    (this->*harls[i])();
}
