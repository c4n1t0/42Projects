/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:47:37 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/01 23:45:37 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie
{
    private:
        std::string name;

    public:
        Zombie(std::string _name);
        ~Zombie(void);
        void    announce(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif