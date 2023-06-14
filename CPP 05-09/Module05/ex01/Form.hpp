/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:58:39 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/02 18:46:48 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const   name;
        bool                signedStatus;
        int const           gradeSigned;
        int const           gradeExec;
        
    public:
        Form(void);
        Form(Form const &copy);
        Form(std::string const _name, int const _gradeSigned, int const _gradeExec);
        ~Form(void);

        Form&   operator=(Form const &pointer);

        std::string const   getName(void) const;
        bool                getSignedStatus(void);
        int                 getGradeSigned(void) const;
        int                 getGradeExec(void) const;
        void                beSigned(Bureaucrat &pointer);

        class GradeTooHighException : public std::exception
        {
            private:
                std::string _strerror;
            public:
                GradeTooHighException(const std::string &str) : _strerror(str) {}
                virtual ~GradeTooHighException(void) _NOEXCEPT {}
                const char* what() const _NOEXCEPT { return _strerror.c_str(); }
        };

        class GradeTooLowException : public std::exception
        {
            private:
                std::string _strerror;
            public:
                GradeTooLowException(const std::string &str) : _strerror(str) {}
                virtual ~GradeTooLowException(void) _NOEXCEPT {}
                const char* what() const _NOEXCEPT { return _strerror.c_str(); }    
        };
};

std::ostream    &operator<<(std::ostream &out, Form &pointer);

#endif