/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:43:13 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/11 23:29:28 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "[Cat Class] Default constructor called\n";
}

Cat::~Cat(void)
{
    std::cout << "[Cat Class] Default destructor called\n";
}

void    Cat::makeSound(void) const
{
    std::cout << "[Cat Class] The cat say Miaouuuuu!\n";
}
