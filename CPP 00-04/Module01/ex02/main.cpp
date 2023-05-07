/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:02:45 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/06 13:39:54 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string stringSTR = "HI THIS IS BRAIN";
    std::string *stringPTR = &stringSTR;
    std::string &stringREF = stringSTR;

    std::cout << "\n\tDriecciones de Memoria:" << std::endl;
    std::cout << "Dirección de memoria str: " << &stringSTR << std::endl;
    std::cout << "Dirección de memoria ptr: " << stringPTR << std::endl;
    std::cout << "Dirección de memoria ref: " << &stringREF << std::endl;

    std::cout << "\n\tContenido del valor apuntado:" << std::endl;
    std::cout << "Valor str: " << stringSTR << std::endl;
    std::cout << "Valor ptr: " << *stringPTR << std::endl;
    std::cout << "Valor ref: " << stringREF << std::endl;

    return (0);
}
