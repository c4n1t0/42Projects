/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:41:44 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/11 22:49:46 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
    protected:
        std::string type;
        
    public:
        Animal(void);
        Animal(std::string _type);
        Animal(const Animal &copy);
        virtual ~Animal(void);

        Animal&             operator=(const Animal &pointer);
        virtual void        makeSound(void) const;
        std::string         getType(void) const;
};

#endif