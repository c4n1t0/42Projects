/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:31:44 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/10 12:57:29 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    system("clear");
    std::cout << "\n<------- Pruebas constructores, copias e igualaciones -------->\n" << std::endl;
    {
        Bureaucrat  bur1("javi", 1);
        Form        form1("form1", 1, 1);
        Form        form2;
        Form        form3(form1);

        std::cout << bur1;
        std::cout << form1;
        std::cout << form2;
        std::cout << form3;
        form1.beSigned(bur1);
        form2 = form1;
        std::cout << form1;
        std::cout << form2;
    }
    std::cout << "\n<------- Pruebas firmas de burocratas -------->\n" << std::endl;
    {
        Bureaucrat  bur1("javi", 1);
        Bureaucrat  bur2("Maria", 50);
        Bureaucrat  bur3("Carla", 10);
        Form        form1("Formulario 1", 9, 20);

        std::cout << bur1 << bur2 << bur3 << form1;
        form1.beSigned(bur3);
        form1.beSigned(bur2);
        form1.beSigned(bur1);
    }
    std::cout << "\n<------- Pruebas Exceptions! -------->\n" << std::endl;
    {
        Bureaucrat  bur1("Jhony", 1);
        Form        form1("Formulario 1", 0, 0);
        Form        form2("Formulario 2", 151, 151);

        form1.beSigned(bur1);
        form2.beSigned(bur1);
        std::cout << form1 << form2;
    }
    return (0);
}
