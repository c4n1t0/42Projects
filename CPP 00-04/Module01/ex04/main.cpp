/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 00:19:58 by jaromero          #+#    #+#             */
/*   Updated: 2023/03/06 20:13:20 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReadFile.hpp"

void    leaks(void)
{
    system("leaks -q ThirstIsForSuckers");
}

int main(int argc, char **argv)
{
    atexit(leaks);
    if (argc != 4)
    {
        std::cout << "Invalid arguments" << std::endl;
        return (1);
    }
    ReadFile read (argv[1]);
    read.SaveFile();
    read.ReplaceString(argv[2], argv[3]);
    read.SaveToFileReplace();
    return (0);
}
