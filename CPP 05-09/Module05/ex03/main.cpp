/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:31:44 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/14 13:32:54 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void    leaks(void)
{
    system("leaks -q InternForm");
}

int main(void)
{
    system("clear");
    atexit(leaks);
    {
        Bureaucrat javi("javi", 5);
        Intern mary;
        AForm *ptr;
        
        ptr = mary.makeForm("presidential pardon", "House");
        if (ptr != nullptr)
        {
            std::cout << *ptr;
            ptr->beSigned(javi);
            ptr->execute(javi);
            std::cout << *ptr;
            delete ptr;
        }
    }
    std::cout << std::endl;
    return (0);
}
