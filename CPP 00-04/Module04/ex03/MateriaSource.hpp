/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:30:34 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/21 11:28:13 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "iostream"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria    *materias[4];

    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const &copy);
        ~MateriaSource(void);

        MateriaSource&  operator=(MateriaSource const &pointer);
        void            learnMateria(AMateria*);
        AMateria*       createMateria(std::string const & type);
    
};

#endif