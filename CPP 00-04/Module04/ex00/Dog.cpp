/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:35:03 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/11 23:29:22 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "[Dog Class] Default constructor called\n";
}

Dog::~Dog(void)
{
    std::cout << "[Dog Class] Default destructor called\n";
}

void    Dog::makeSound(void) const
{
    std::cout << "[Dog Class] The dog say GUAU GUAU!\n";
}
