/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:13:46 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/09 13:14:15 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;

    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string _target);
        RobotomyRequestForm(RobotomyRequestForm &copy);
        ~RobotomyRequestForm(void);

    RobotomyRequestForm&    operator=(RobotomyRequestForm &pointer);

    void    execute(Bureaucrat const & executor) const;
};

#endif