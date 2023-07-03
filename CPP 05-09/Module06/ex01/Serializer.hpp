/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:35:52 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/26 18:58:34 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

struct Data
{
    int nbr;
};

class Serializer
{
    public:
        Serializer(void);
        Serializer(Serializer &copy);
        ~Serializer(void);
        Serializer& operator=(Serializer &pointer);

        uintptr_t	serialize(Data *ptr);
        Data*       deserialize(uintptr_t raw);
};

#endif