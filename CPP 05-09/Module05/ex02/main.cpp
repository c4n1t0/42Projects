/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:31:44 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/14 12:44:54 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    system("clear");
    std::cout << "\n<------- ShrubberyCreationForm test`s -------->\n" << std::endl;
    {
        ShrubberyCreationForm   form("House");
        ShrubberyCreationForm   form1("Mountain");
        ShrubberyCreationForm   form2("Beach");
        Bureaucrat  bur1("javi", 130);

        std::cout << "\n\tShrubberyCreationForm OK test`s\n" << std::endl;   
        form.beSigned(bur1);
        std::cout << "\nForm: " << form << std::endl << "Form1: " << form1 << std::endl;
        form1.beSigned(bur1);
        std::cout << "\nForm: " << form << std::endl << "Form1: " << form1 << std::endl;
        form.execute(bur1);
        std::cout << std::endl;
        form1.execute(bur1);
        std::cout << "\n\n\tShrubberyCreationForm KO test`s\n" << std::endl;
        bur1.decrementGrade(20);
        std::cout << std::endl;
        form2.beSigned(bur1);
        form2.execute(bur1);
        form.execute(bur1);
    }
    std::cout << "\n<------- RobotomyRequestForm test`s -------->\n" << std::endl;
    {
        RobotomyRequestForm   form("House");
        RobotomyRequestForm   form1("Mountain");
        RobotomyRequestForm   form2("Beach");
        Bureaucrat  bur1("javi", 45);

        std::cout << "\n\tRobotomyRequestForm OK test`s\n" << std::endl;   
        form.beSigned(bur1);
        std::cout << "\nForm: " << form << std::endl << "Form1: " << form1 << std::endl;
        form1.beSigned(bur1);
        std::cout << "\nForm: " << form << std::endl << "Form1: " << form1 << std::endl;
        form.execute(bur1);
        std::cout << std::endl;
        form1.execute(bur1);
        std::cout << "\n\n\tRobotomyRequestForm KO test`s\n" << std::endl;
        bur1.decrementGrade(31);
        std::cout << std::endl;
        form2.beSigned(bur1);
        form2.execute(bur1);
        form.execute(bur1);
    }
    std::cout << "\n<------- PresidentialPardonForm test`s -------->\n" << std::endl;
    {
        PresidentialPardonForm   form("House");
        PresidentialPardonForm   form1("Mountain");
        PresidentialPardonForm  form2("Beach");
        Bureaucrat  bur1("javi", 5);

        std::cout << "\n\tPresidentialPardonForm OK test`s\n" << std::endl;   
        form.beSigned(bur1);
        std::cout << "\nForm: " << form << std::endl << "Form1: " << form1 << std::endl;
        form1.beSigned(bur1);
        std::cout << "\nForm: " << form << std::endl << "Form1: " << form1 << std::endl;
        form.execute(bur1);
        std::cout << std::endl;
        form1.execute(bur1);
        std::cout << "\n\n\tPresidentialPardonForm KO test`s\n" << std::endl;
        bur1.decrementGrade(21);
        std::cout << std::endl;
        form2.beSigned(bur1);
        form2.execute(bur1);
        form.execute(bur1);
    }
    return (0);
}
