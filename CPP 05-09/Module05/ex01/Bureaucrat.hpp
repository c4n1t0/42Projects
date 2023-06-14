/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:51:16 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/02 18:22:55 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string const   name;
        int                 grade;
       
    public:
        Bureaucrat(void);
        Bureaucrat(Bureaucrat const &copy);
        Bureaucrat(std::string const _name, int _grade);
        ~Bureaucrat(void);

        Bureaucrat&     operator=(Bureaucrat const &pointer);

        std::string const       getName(void) const;
        int                     getGrade(void) const;
        void                    incrementGrade(int _increment);
        void                    decrementGrade(int _decrement);
        void                    signForm(Form &ptr);

        class GradeTooHighException : public std::exception
        {
            private:
                std::string _strerror;
            public:
                GradeTooHighException(const std::string& str) : _strerror(str) {}
                virtual ~GradeTooHighException() _NOEXCEPT {}  
                const char* what() const _NOEXCEPT { return _strerror.c_str(); }
        };

        class GradeTooLowException : public std::exception
        {
            private:
                std::string _strerror;
            public:
                GradeTooLowException(const std::string& str) : _strerror(str) {}
                virtual ~GradeTooLowException(void) _NOEXCEPT {}
                const char* what() const _NOEXCEPT { return _strerror.c_str(); }
        };
        
};

std::ostream    &operator<<(std::ostream &out, Bureaucrat const &pointer);

#endif