/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:40:34 by jaromero          #+#    #+#             */
/*   Updated: 2023/05/29 00:26:55 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void    leaks(void)
{
    system("leaks -q Brain");
}

int main(void)
{
    atexit(leaks);
    std::cout << std::endl << "<-_-_-_- Test Subject -_-_-_->\n" << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        delete j;//should not create a leak
        delete i;
    }
    std::cout << "\n<-_-_-_- Correction! -_-_-_->\n" << std::endl;
    {
        Dog basic;
        {
            Dog tmp(basic);
            tmp = basic;
        }
    }
    std::cout << std::endl << "<-_-_-_- Test for Animals -_-_-_->\n" << std::endl;
    {
        const Animal* animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
        int x;
        
        x = 0;
        while (x < 4)
            delete animals[x++];
    }
    std::cout << std::endl;
    return (0);
}