/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 13:20:52 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/12 13:11:32 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(Intern &copy)
{
    *this = copy;
}

Intern::~Intern(void)
{
}

Intern& Intern::operator=(Intern &pointer)
{
    (void)pointer;
    return (*this);
}

AForm*   Intern::makeForm(std::string _form, std::string _target)
{
    std::string formsName[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *forms[3] = {new ShrubberyCreationForm(_target),  new RobotomyRequestForm(_target),
                         new PresidentialPardonForm(_target)};
    int i;
    int x;
    
    i = 0;
    while (i < 3)
    {
        if (_form.compare(formsName[i]) == 0)
        {
            std::cout << "Intern creates " << _form << std::endl;
            x = 0;
            while (x < 3)
            {
                if (x != i)
                    delete forms[x];
                x++;
            }       
            return (forms[i]);
        }
        i++;
    }
    i = 0;
    while (i < 3)
        delete forms[i++];
    std::cout << "Intern can´t create form " << _form << std::endl;
    return (nullptr);
}
