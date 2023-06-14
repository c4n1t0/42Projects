/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:16:52 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/09 13:26:39 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = _target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm(copy), target(copy.target)
{
	this->target = copy.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(ShrubberyCreationForm &pointer)
{
	this->target = pointer.target;
	return (*this);
}

void        ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string replace = target + "_shrubbery";

	try
	{
		if (AForm::getSignedStatus() == false)
			throw	FormNotSignedException("Impossible to execute, the form is not signed!\n");
		else if (executor.getGrade() <= AForm::getGradeExec())
		{
			std::ofstream outfile (replace);
			outfile << "                                                         .\n";
			outfile << "                                              .         ;  \n";
			outfile << "                 .              .              ;%     ;;   \n";
			outfile << "                   ,           ,                :;%  %;   \n";
			outfile << "                    :         ;                   :;%;'     .,   \n";
			outfile << "           ,.        %;     %;            ;        %;'    ,;\n";
			outfile << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
			outfile << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n";
			outfile << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
			outfile << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
			outfile << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
			outfile << "                    `:%;.  :;bd%;          %;@%;'\n";
			outfile << "                      `@%:.  :;%.         ;@@%;'   \n";
			outfile << "                        `@%.  `;@%.      ;@@%;         \n";
			outfile << "                          `@%%. `@%%    ;@@%;        \n";
			outfile << "                            ;@%. :@%%  %@@%;       \n";
			outfile << "                              %@bd%%%bd%%:;     \n";
			outfile << "                                #@%%%%%:;;\n";
			outfile << "                                %@@%%%::;\n";
			outfile << "                                %@@@%(o);  . '         \n";
			outfile << "                                %@@@o%;:(.,'         \n";
			outfile << "                            `.. %@@@o%::;         \n";
			outfile << "                               `)@@@o%::;         \n";
			outfile << "                                %@@(o)::;        \n";
			outfile << "                               .%@@@@%::;         \n";
			outfile << "                               ;%@@@@%::;.          \n";
			outfile << "                              ;%@@@@%%:;;;. \n";
			outfile << "                          ...;%@@@@@%%:;;;;,..\n";
			outfile.close();
			std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		}
		else
			throw GradeTooLowException("Bureucrat grade is too low to execute!\n");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

