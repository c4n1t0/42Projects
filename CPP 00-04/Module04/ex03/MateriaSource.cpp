/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 01:31:58 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/22 23:42:48 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    int i;

    std::cout << "[MateriaSource Class] default constructor called\n";
    i = 0;
    while (i < 4)
    {
        this->materias[i] = NULL;
        i++;
    }
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
    int i;

    std::cout << "[MateriaSource class] copy constructor called\n";
    i = 0;
    while (i < 4)
    {
        if (copy.materias[i])
            this->materias[i] = copy.materias[i]->clone();
        else
            this->materias[i] = NULL;
        i++;
    }
}

MateriaSource::~MateriaSource(void)
{
    int i;

    std::cout << "[MateriaSource class] default destructor called\n";
    i = 0;
    while (i < 4)
    {
        if (this->materias[i])
        {
            delete materias[i];
            materias[i] = NULL;
        }
        i++;
    }
}

MateriaSource&  MateriaSource::operator=(MateriaSource const &pointer)
{
    int i;

    std::cout << "[MateriaSource class] Asignation operator called\n";
    i = 0;
    while (i < 4)
    {
        if (pointer.materias[i])
            this->materias[i] = pointer.materias[i]->clone();
        i++;
    }
    return (*this);
}

void    MateriaSource::learnMateria(AMateria *m)
{
    int i;

    i = 0;
    if (!m)
    {
        std::cout << "[MateriaSource class] can´t learn materia, materia doesn´t exist!\n";
        return ;
    }
    while (i < 4)
    {
        if (!this->materias[i])
        {
            std::cout << "[MateriaSource class] add new materia " << m->getType() << std::endl;
            this->materias[i] = m;
            return ;
        }
        i++;
    }
    std::cout << "[MateriaSource class] Can´t add new materia " << m->getType() << " because all slots are full!\n";
    delete m;
}

AMateria*   MateriaSource::createMateria(std::string const & type)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (this->materias[i] && this->materias[i]->getType() == type)
        {
            std::cout << "[MateriaSource class] created new materia " << type << std::endl;
            return (materias[i]->clone());    
        }
        i++;
    }
    std::cout << "[MateriaSource class] Can´t create new materia " << type << std::endl;
    return (NULL);
}
