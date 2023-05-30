/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:41:44 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/15 12:45:33 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
#define AANIMAL_H

#include <iostream>

class AAnimal
{
    protected:
        std::string type;
        
    public:
        AAnimal(void);
        AAnimal(std::string _type);
        AAnimal(const AAnimal &copy);
        virtual ~AAnimal(void);

        virtual AAnimal&    operator=(const AAnimal &pointer);
        virtual void        makeSound(void) const = 0;
        std::string         getType(void) const;
};

#endif