/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:07:55 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/21 22:58:27 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include "iostream"
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;
        
    public:
        AMateria(void);
        AMateria(std::string const & type);
        AMateria(AMateria const &copy);
        virtual ~AMateria(void);

        AMateria&           operator=(AMateria const &pointer);
        std::string const&  getType() const;
        virtual AMateria*   clone() const = 0;
        virtual void        use(ICharacter& target);
};

#endif