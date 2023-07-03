/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:02:21 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/29 19:19:22 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>

void PrintValue(T& value)
{
    std::cout << value << " ";
}

void Funct(int &x)
{
    x = x * x;
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    std::string str[3] = {"hola", "amigo", "mio"};

    iter(array, 5, PrintValue<int>);
    std::cout << std::endl;
    iter(array, 5, Funct);
    iter(array, 5, PrintValue<int>);
    std::cout << std::endl;
    iter(str, 3, PrintValue<std::string>);
    std::cout << std::endl;
    return 0;
}
