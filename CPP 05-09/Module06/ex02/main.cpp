/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:31:47 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/26 18:56:06 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    int i;

    std::srand(std::time(0));
    i = std::rand() % 3;
    std::cout << "Random Value: " << i << std::endl << std::endl;
    switch (i)
    {
    case 0 :
        return (new A);
        break;
    case 1 :
        return (new B);
        break;
    case 2 :
        return (new C);
        break;
    default:
        break;
    }
    return (new Base);
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "El puntero aleatorio es de tipo A\n\n" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "El puntero aleatorio es de tipo B\n\n" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "El puntero aleatorio es de tipo C\n\n" << std::endl;
    else
        std::cerr << "Error, Unknown type!\n\n";
}

void identify(Base &p)
{
    int i;

    i = 0;
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "El puntero aleatorio es de tipo: A\n\n";
    }
    catch(const std::exception& e)
    {
        i++;
    }
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "El puntero aleatorio es de tipo: B\n\n";
    }
    catch(const std::exception& e)
    {
        i++;
    }
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "El puntero aleatorio es de tipo: C\n\n";
    }
    catch(const std::exception& e)
    {
        i++;
    }
    if (i == 3)
        std::cerr << "Error, Unknown type!\n\n";
}

void    leaks(void)
{
    system("leaks -q RealType");
}

int main(void)
{
    Base*   base;

    atexit(leaks);
    base = generate();
    identify(base);
    identify(*base);
    delete base;
    return (0);
}