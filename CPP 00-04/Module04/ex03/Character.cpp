/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:10:13 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/22 23:26:17 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
    int i;

    this->name = "Void";
    i = 0;
    std::cout << "[Character class] default constructor called\n";
    while (i < 4)
    {
        inventory[i] = NULL;
        i++;
    }
}

Character::Character(std::string _name) : name(_name)
{
    int i;

    i = 0;
    std::cout << "[Character class] name constructor called\n";
    while (i < 4)
    {
        inventory[i] = NULL;
        i++;
    }
}

Character::Character(Character const &copy)
{
    int i;

    std::cout << "[Character class] copy constructor called\n";
    this->name = copy.name;
    i = 0;
    while (i < 4)
    {
        if (copy.inventory[i])
            this->inventory[i] = copy.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
        i++;
    }
}

Character::~Character(void)
{
    int i;
    
    std::cout << "[Character class] default destructor called\n";
    i = 0;
    while (i < 4)
    {
        if (this->inventory[i])
        {
            delete (this->inventory[i]);
            this->inventory[i] = NULL;
        }
        i++;
    }
}

Character&  Character::operator=(Character const &pointer)
{
    int i;

    std::cout << "[Character class] asignation operator called\n";
    this->name = pointer.name;
    i = 0;
    while (i < 4)
    {
        if (pointer.inventory[i])
            this->inventory[i] = pointer.inventory[i]->clone();
        i++;
    }
    return (*this);
}

std::string const& Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria *m)
{
    int i;

    i = 0;
    if (!m)
    {
        std::cout << "[Character class] can´t equip, materia doesn´t exist!\n";
        return ;
    }
    while (i < 4)
    {
        if (!this->inventory[i])
        {
            this->inventory[i] = m;
            std::cout << "[Character class] " << this->name << " equip " 
                    << this->inventory[i]->getType() << std::endl;
            return ;
        }
        i++;
    }
    std::cout << "[Character class] " << this->name << " Can´t equip " 
            << m->getType() << " because all slots if full\n";
    delete m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        std::cout << "[Character class] Cant´t unequip beacuse bad index!\n";
    else if (!this->inventory[idx])
        std::cout << "[Character class] Cant´t unequip beacuse this is a free slot!\n";
    else
    {
        std::cout << "[Character class] " << this->name << " unequip " 
                << this->inventory[idx]->getType() << std::endl;
        delete this->inventory[idx];
        this->inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (this->inventory[idx] && idx > -1 && idx < 4)
    {
        std::cout << "[Character class] " << this->name << " use " 
                << this->inventory[idx]->getType() << std::endl;
        this->inventory[idx]->use(target);
    }
    else
        std::cout << "[Character class] " << this->name << " Can´t use, does no´t exist." << std::endl;
}