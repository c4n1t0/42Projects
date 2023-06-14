/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:58:39 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/03 19:19:25 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const   name;
        bool                signedStatus;
        int const           gradeSigned;
        int const           gradeExec;
        
    public:
        AForm(void);
        AForm(AForm const &copy);
        AForm(std::string const _name, int const _gradeSigned, int const _gradeExec);
        ~AForm(void);

        AForm&   operator=(AForm const &pointer);

        std::string const   getName(void) const;
        bool                getSignedStatus(void) const;
        int                 getGradeSigned(void) const;
        int                 getGradeExec(void) const;
        void                beSigned(Bureaucrat &pointer);
        virtual void        execute(Bureaucrat const & executor) const = 0;

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
        class FormNotSignedException : public std::exception
        {
            private:
                std::string _strerror;
            public:
                FormNotSignedException(const std::string &str) : _strerror(str) {}
                virtual ~FormNotSignedException(void) _NOEXCEPT {}
                const char* what() const _NOEXCEPT { return _strerror.c_str(); }    
        };
};

std::ostream    &operator<<(std::ostream &out, AForm &pointer);

#endif