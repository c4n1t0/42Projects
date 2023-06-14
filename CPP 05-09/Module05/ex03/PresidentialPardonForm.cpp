/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:12:12 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/09 13:33:52 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5)
{
    this->target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardonForm", 25, 5)
{
    this->target = _target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm(copy)
{
    this->target = copy.target;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &pointer)
{
    this->target = pointer.target;
    return (*this);
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    try
    {
        if (AForm::getSignedStatus() == false)
            throw   FormNotSignedException("Impossible to execute, the form is not signed!\n");
        else if (executor.getGrade() <= AForm::getGradeExec())
        {
            std::cout << executor.getName() << " executed " << this->getName() << std::endl;
            std::cout << "Informs that " << this->target << " has been pardoned by Zaphod Beeblebrox\n";
        }
        else
            throw   GradeTooLowException("Bureucrat grade is too low to execute!\n");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}