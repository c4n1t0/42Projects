/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:33:49 by jaromero          #+#    #+#             */
/*   Updated: 2023/06/26 20:23:42 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template < typename T1 >

void    swap(T1 &a, T1 &b)
{
    T1  tmp = a;

    a = b;
    b = tmp;
}

template < typename T2 >

T2  min(T2 &a, T2 &b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

template < typename T3 >

T3  max(T3 &a, T3 &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

#endif