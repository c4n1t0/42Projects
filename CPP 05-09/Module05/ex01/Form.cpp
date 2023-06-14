/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:40:52 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/10 13:00:18 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("void"), signedStatus(false), gradeSigned(150), gradeExec(150)
{
}

Form::Form(Form const &copy) : name(copy.name), signedStatus(copy.signedStatus), 
        gradeSigned(copy.gradeSigned), gradeExec(copy.gradeExec)
{
    try
    {
        if (gradeSigned < 1)
            throw GradeTooHighException("Error, Grade too high to create form!!\n");
        if (gradeSigned > 150)
            throw GradeTooLowException("Error, Grade too low to create form!!\n");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Form::Form(std::string const _name, int const _gradeSigned, int const _gradeExec) : 
name(_name), gradeSigned(_gradeSigned), gradeExec(_gradeExec)
{
    this->signedStatus = false;
    try
    {
        if (gradeSigned < 1)
            throw GradeTooHighException("Error, Grade too high to create form!!\n");
        if (gradeSigned > 150)
            throw GradeTooLowException("Error, Grade too low to create form!!\n");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Form::~Form(void)
{
}

Form&   Form::operator=(Form const &pointer)
{
    this->signedStatus = pointer.signedStatus;
    return (*this);
}

std::string const   Form::getName(void) const
{
    return (this->name);
}

bool    Form::getSignedStatus(void)
{
    return (this->signedStatus);
}

int   Form::getGradeSigned(void) const
{
    return (this->gradeSigned);
}

int   Form::getGradeExec(void) const
{
    return (this->gradeExec);
}

void    Form::beSigned(Bureaucrat &pointer)
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

std::ostream    &operator<<(std::ostream &out, Form &ptr)
{
    out << "The form " << ptr.getName() << " has a grade to signed " << ptr.getGradeSigned() 
                << " and a grade to exec " << ptr.getGradeExec();
    if (ptr.getSignedStatus() == false)
        out << " has not been signed!!" << std::endl;
    else
        out << " has been signed!!" << std::endl;
    return (out);
}
