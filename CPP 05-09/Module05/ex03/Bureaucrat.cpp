/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:18:39 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/14 12:42:53 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("void")
{
    this->grade = 150;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
    *this = copy;
}

Bureaucrat::Bureaucrat(std::string const _name, int _grade) : name(_name)
{
    try
    {
        if (_grade < 1)
        {
            this->grade = 1;
            throw GradeTooHighException("Error, Grade too high!!\n");
        }
        else if (_grade > 150)
        {
            this->grade = 150;
            throw GradeTooLowException("Error, Grade too low!!\n");
        }
        else
            this->grade = _grade;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &pointer)
{
    this->grade = pointer.grade;
    return (*this);
}

std::ostream    &operator<<(std::ostream &out, Bureaucrat const &pointer)
{
    out << pointer.getName() << ", bureaucrat grade " << pointer.getGrade() << "." << std::endl;
    return (out);
}

std::string const   Bureaucrat::getName(void) const
{
    return (this->name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->grade);
}

void    Bureaucrat::incrementGrade(int _increment)
{    
    try
    {
        if (this->grade - _increment > 0)
        {
            this->grade -= _increment;
            std::cout << this->name << " Increment grade to " << this->getGrade() << std::endl;
        }    
        else
            throw GradeTooHighException("Error, Grade too high!!\n");
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void    Bureaucrat::decrementGrade(int _decrement)
{
    try
    {
        if (this->grade + _decrement <= 150)
        {
            this->grade += _decrement;
            std::cout << this->name << " Decrement grade to " << this->getGrade() << std::endl;
        }
        else
            throw GradeTooLowException("Error, Grade too low!!\n");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void    Bureaucrat::signForm(AForm &ptr)
{
    if (ptr.getSignedStatus() == false && ptr.getGradeSigned() > 0 && ptr.getGradeSigned() <= 150)
        std::cout << getName() << " signed " << ptr.getName() << std::endl;
    else if (ptr.getSignedStatus() == true)
        std::cout << getName() << " couldn’t sign " 
                    << ptr.getName() << " because has already been signed\n";
}

void    Bureaucrat::executeForm(AForm const & form) const
{
    form.execute(*this);
}
