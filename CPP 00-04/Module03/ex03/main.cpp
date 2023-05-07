/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 00:10:36 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/04 01:23:33 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main( void )
{
    DiamondTrap monsterkill("Aurelio");
    DiamondTrap ultrakill("ASDF");
    DiamondTrap humillation("Phoenix");

    monsterkill.whoAmI();
    ultrakill.whoAmI();
    humillation = monsterkill;
    humillation.whoAmI();

    monsterkill.attack( "the air" );
    ultrakill.takeDamage( 10 );
    ultrakill.beRepaired( 30 );

    return EXIT_SUCCESS;
}