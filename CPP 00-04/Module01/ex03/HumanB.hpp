/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:05:46 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/07 01:31:22 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include "Weapon.hpp"

class   HumanB
{
    private:
        std::string name;
        Weapon  *gun;
    public:
        HumanB(std::string _name);
        ~HumanB(void);
        void    attack(void);
        void    setWeapon(Weapon &gun);
    
};

#endif