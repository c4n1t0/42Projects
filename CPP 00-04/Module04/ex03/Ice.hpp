/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:12:26 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/17 01:30:48 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Ice_H
#define Ice_H

#include "AMateria.hpp"
#include "ICharacter.hpp"


class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(const Ice &copy);
        virtual ~Ice(void);

        Ice&            operator=(const Ice &pointer);
        virtual void    use(ICharacter&);
        virtual Ice*    clone(void) const;  
};

#endif