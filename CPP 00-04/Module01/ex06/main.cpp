/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:21:02 by jaromero          #+#    #+#             */
/*   Updated: 2023/03/01 18:29:05 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int argc, char **argv)
{
    Harl        exec;
    
    if (argc != 2)
    {
        std::cout << "\nError. Too many arguments\n";
        return (1);
    }
    exec.complain(argv[1]);
    return (0);
}
