/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:15:23 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/15 12:11:36 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* ideas;
        
    public:
        Dog(void);
        Dog(const Dog &copy);
        virtual ~Dog(void);

        Dog&    operator=(const Dog &pointer);
        void    makeSound(void) const;
};

#endif