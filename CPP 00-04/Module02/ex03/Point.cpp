/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:06:46 by jaromero          #+#    #+#             */
/*   Updated: 2023/03/06 17:49:36 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(), y()
{
}

Point::Point(const Point &temp) : x(temp.x), y(temp.y)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point&  Point::operator=(const Point &pointer)
{    
    (Fixed) this->x = pointer.x;
    (Fixed) this->y = pointer.y;
    return (*this);
}

Point::~Point(void)
{
}

Fixed   Point::getX(void) const
{
    return (this->x);
}

Fixed   Point::getY(void) const
{
    return (this->y);
}
