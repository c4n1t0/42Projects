/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:49:57 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/03 00:04:10 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
 public:

        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap &copy);
        ~FragTrap();

        void highFivesGuys(void);
};

#endif