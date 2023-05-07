/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:08:32 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/03 12:03:47 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
 public:

        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap &copy);
        ~FragTrap();

        void highFivesGuys(void);
};

#endif