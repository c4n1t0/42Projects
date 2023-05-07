/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:07:32 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/03 00:07:35 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
    protected:

        std::string		_name;
        unsigned int	_hitPoints;
        unsigned int	_energyPoints;
        unsigned int	_attackDamage;
        
    public:
        
        ClapTrap(void);
        ClapTrap(std::string _name);
        ClapTrap(const ClapTrap &copy);
        ~ClapTrap();
        
        ClapTrap&  operator=(const ClapTrap &pointer);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif