/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:57:07 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/22 00:14:10 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class   Character : public ICharacter
{
    private:
        AMateria    *inventory[4];
        std::string name;
    
    public:
        Character(void);
        Character(std::string const _name);
        Character(Character const &copy);
        virtual~Character(void);
        Character &operator=(Character const &pointer);

        std::string const&  getName() const;
        void                equip(AMateria *m);
        void                unequip(int idx);
        void                use(int idx, ICharacter &target);
};

#endif