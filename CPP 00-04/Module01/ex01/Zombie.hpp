/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:00:54 by jaromero          #+#    #+#             */
/*   Updated: 2023/02/06 12:52:59 by jaromero         ###   ########.fr       */
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
        Zombie(void);
        ~Zombie(void);
        void    initZombie(std::string nick);
        void    announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif