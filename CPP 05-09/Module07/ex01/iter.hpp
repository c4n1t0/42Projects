/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:02:53 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/27 20:13:23 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T1, typename T2>

void    iter(T1* str, size_t length, T2 funct)
{
    size_t i;

    i = 0;
    while (i < length)
        funct(str[i++]);
}

#endif