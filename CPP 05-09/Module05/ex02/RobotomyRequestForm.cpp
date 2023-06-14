/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:13:43 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/09 13:31:21 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45)
{
    this->target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("RobotomyRequestForm", 72, 45)
{
    this->target = _target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm(copy), target(copy.target)
{
    this->target = copy.target;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm&    RobotomyRequestForm::operator=(RobotomyRequestForm &pointer)
{
    this->target = pointer.target;
    return (*this);
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    try
    {
        if (AForm::getSignedStatus() == false)
            throw   FormNotSignedException("Impossible to execute, the form is not signed!\n");
        else if (executor.getGrade() <= AForm::getGradeExec())
        {
            std::cout << executor.getName() << " executed " << this->getName() << std::endl;
            std::cout << this->target << " has been robotomized successfully 50% of the time\n";
        }
        else
            throw GradeTooLowException("Bureucrat grade is too low to execute!\n");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
