/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:40:34 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/15 12:51:33 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void    leaks(void)
{
    system("leaks -q Animals");
}

int main(void)
{
    std::cout << std::endl << "<-_-_-_- Test for Animal -_-_-_->\n" << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        
        atexit(leaks);
        std::cout << j->getType() << " Type Animal from pointer J" << std::endl;
        std::cout << meta->getType() << " Type Animal from pointer meta" << std::endl;
        std::cout << i->getType() << " Type Animal from pointer i" << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();
        delete j;
        delete i;
        delete meta;
    }
        std::cout << std::endl << "<-_-_-_- Test for WrongAnimal -_-_-_->\n" << std::endl;
    {
        const WrongAnimal *animal = new WrongAnimal();
        const WrongAnimal *cat = new WrongCat();

        std::cout << animal->getType() << " Type Animal from pointer animal" << std::endl;
        std::cout << cat->getType() << " Type Animal from pointer cat" << std::endl;
        animal->makeSound();
        cat->makeSound();
        delete  animal;
        delete  cat;
        std::cout << std::endl;
    }
    return (0);
}