/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:01:49 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/16 13:07:59 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (void)
{
    int         i;
    Harl        exec;
    std::string level;
    std::string command[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    std::cout << "\nChoose level: DEBUG, INFO, WARNING, ERROR.\n\nLevel: ";
    getline(std::cin, level);
    i = 0;
    while (i < 4 && command[i].compare(level))
        i++;
    if (i == 4)
    {
        std::cout << "Bad syntax of level!" << std::endl;
        return (1);
    }
    exec.complain(level);
    return (0);
}
