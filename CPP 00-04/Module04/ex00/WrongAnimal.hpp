/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:58:57 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/11 23:19:34 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal(void);
        WrongAnimal(std::string _type);
        WrongAnimal(const WrongAnimal &copy);
        ~WrongAnimal(void);

        WrongAnimal&    operator=(const WrongAnimal &pointer);
        void            makeSound(void) const;
        std::string     getType(void) const;
};

#endif