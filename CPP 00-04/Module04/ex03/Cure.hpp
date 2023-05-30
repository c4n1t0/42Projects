/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:13:34 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/17 01:43:36 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_H
#define Cure_H

#include "AMateria.hpp"
#include "Character.hpp"

class Cure : public AMateria
{
    public:
        Cure(void);
        Cure(const Cure &copy);
        virtual ~Cure(void);

        Cure&   operator=(const Cure &pointer);
        virtual void use(ICharacter&);
        virtual Cure*   clone(void) const;  
};

#endif