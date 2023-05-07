/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:06:01 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/06 23:19:52 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>

class Weapon
{
    private:
        std::string type;
    public:
        Weapon(std::string  data);
        ~Weapon(void);
        std::string&    getType();
        void            setType(std::string _type);

};

#endif