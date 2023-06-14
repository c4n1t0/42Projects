/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:31:44 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/14 11:48:02 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    Bureaucrat asdf("Javi", 50);
    Bureaucrat re ("Alberto", 150);

    std::cout << re << std::endl;
    re.decrementGrade(1);
    std::cout << asdf << std::endl;
    asdf.incrementGrade(50);
    std::cout << "Post increment " << asdf << std::endl;
    asdf.decrementGrade(149);
    std::cout << "Post decrement " << asdf << std::endl;
    std::cout << asdf << std::endl;
    return (0);
}
