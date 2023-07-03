/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:35:43 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/26 18:47:31 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
}

Serializer::Serializer(Serializer &copy)
{
    *this = copy;
}

Serializer::~Serializer(void)
{
}

Serializer& Serializer::operator=(Serializer &pointer)
{
    return (pointer);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*       Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
