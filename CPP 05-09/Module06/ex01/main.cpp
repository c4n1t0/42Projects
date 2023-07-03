/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:31:47 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/26 18:51:32 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

void    leaks(void)
{
    system("leaks -q Serialize");
}

int main(void)
{
    Serializer  srl;
    Data*       data = new Data;
    uintptr_t   raw;

    atexit(leaks);
    data->nbr = 1024;
    raw = srl.serialize(data);
    std::cout << "Valor del puntero serializado: " << raw << " y su dirección " 
                << &raw << std::endl;
    std::cout << "Valor de la estructura deserialiada: ";
    std::cout << srl.deserialize(raw)->nbr << ", y su dirección " << srl.deserialize(raw) << std::endl;
    std::cout << "Valor directo de la estructura: ";
    std::cout << data->nbr << ", y su dirección directamente " << data << std::endl << std::endl;
    delete data;

    return (0);
}