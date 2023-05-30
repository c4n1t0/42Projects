/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:31:37 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/15 12:09:39 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* ideas;
        
    public:
        Cat(void);
        Cat(const Cat &copy);
        virtual ~Cat(void);

        Cat&    operator=(const Cat &pointer);
        void    makeSound(void) const;
};

#endif