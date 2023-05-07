/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:06:42 by jaromero          #+#    #+#             */
/*   Updated: 2023/03/06 17:49:39 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"
#include <iostream>

class Point
{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point(void);
        Point(const Point &temp);
        Point(const float x, const float y);
        Point&  operator=(const Point &pointer);
        ~Point(void);

        Fixed   getX(void) const;
        Fixed   getY(void) const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif