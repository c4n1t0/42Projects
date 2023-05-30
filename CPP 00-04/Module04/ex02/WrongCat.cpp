/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 23:18:08 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/11 23:23:41 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    this->type = "WrongCat";
    WrongAnimal::type = "WrongCat";
    std::cout << "[WrongCat Class] Default constructor called\n";
}

WrongCat::~WrongCat(void)
{
    std::cout << "[WrongCat Class] Default destructor called\n";
}

void    WrongCat::makeSound(void) const
{
    std::cout << "[WrongCat Class] The cat say Miaouuuuu!\n";
}

