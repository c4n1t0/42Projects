/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:55:40 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/14 23:01:10 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "[Brain class] Default constructor called\n";
}

Brain::Brain(const Brain &copy)
{
    std::cout << "[Brain class] Copy constructor called\n";
    *this = copy;
}

Brain::~Brain(void)
{
    std::cout << "[Brain class] Default destructor called\n";
}

Brain&  Brain::operator=(const Brain &pointer)
{
    int i;

    i = 0;
    std::cout << "[Brain class] Asignation operator called\n";
    while (i < 100)
    {
        this->ideas[i] = pointer.ideas[i];
        i++;
    }
    return (*this);
}