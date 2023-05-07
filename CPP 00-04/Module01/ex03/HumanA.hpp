/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:05:53 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/06 23:30:38 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include <iostream>
#include "Weapon.hpp"

class   HumanA
{
    private:
        std::string name;
        Weapon  *gun;
    public:
        HumanA(std::string _name, Weapon &gun);
        ~HumanA(void);
        void    attack(void);
    
};

#endif