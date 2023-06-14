/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:12:27 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/09 13:22:01 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;

    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string _target);
        PresidentialPardonForm(PresidentialPardonForm &copy);
        ~PresidentialPardonForm(void);

        PresidentialPardonForm& operator=(PresidentialPardonForm &pointer);

        void    execute(Bureaucrat const & executor) const;
};

#endif