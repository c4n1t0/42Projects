/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:40:52 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/02 22:19:06 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("void"), signedStatus(false), gradeSigned(150), gradeExec(150)
{
}

AForm::AForm(AForm const &copy) : name(copy.name), signedStatus(copy.signedStatus), 
        gradeSigned(copy.gradeSigned), gradeExec(copy.gradeExec)
{
    try
    {
        if (gradeSigned < 1)
            throw GradeTooHighException("Error, Grade too high to signed Aform!!\n");
        if (gradeSigned > 150)
            throw GradeTooLowException("Error, Grade too low to signed Aform!!\n");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

AForm::AForm(std::string const _name, int const _gradeSigned, int const _gradeExec) : 
name(_name), gradeSigned(_gradeSigned), gradeExec(_gradeExec)
{
    this->signedStatus = false;
    try
    {
        if (gradeSigned < 1)
            throw GradeTooHighException("Error, Grade too high to signed Aform!!\n");
        if (gradeSigned > 150)
            throw GradeTooLowException("Error, Grade too low to signed Aform!!\n");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

AForm::~AForm(void)
{
}

AForm&   AForm::operator=(AForm const &pointer)
{
    this->signedStatus = pointer.signedStatus;
    return (*this);
}

std::string const   AForm::getName(void) const
{
    return (this->name);
}

bool    AForm::getSignedStatus(void) const
{
    return (this->signedStatus);
}

int   AForm::getGradeSigned(void) const
{
    return (this->gradeSigned);
}

int   AForm::getGradeExec(void) const
{
    return (this->gradeExec);
}

void    AForm::beSigned(Bureaucrat &pointer)
{
    try
    {
        if (this->gradeSigned < 1)
            throw GradeTooHighException("Error, Grade form is too high!!\n");
        if (this->gradeSigned > 150)
            throw GradeTooLowException("Error, Grade form is too low!!\n");
        if (pointer.getGrade() <= this->gradeSigned && pointer.getGrade() > 0)
        {
            pointer.signForm(*this);
            if (this->signedStatus == false)
                this->signedStatus = true;
        }
        else
            throw GradeTooLowException("Error, Grade to signed is too low!!\n");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

std::ostream    &operator<<(std::ostream &out, AForm &ptr)
{
    out << "The Aform " << ptr.getName() << " has a grade to signed " << ptr.getGradeSigned() 
                << " and a grade to exec " << ptr.getGradeExec();
    if (ptr.getSignedStatus() == false)
        out << " has not been signed!!" << std::endl;
    else
        out << " has been signed!!" << std::endl;
    return (out);
}
