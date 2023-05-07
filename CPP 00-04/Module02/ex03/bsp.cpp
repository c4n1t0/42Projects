/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:06:50 by jaromero          #+#    #+#             */
/*   Updated: 2023/03/06 19:59:58 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed   getArea(Point const one, Point const two, Point const three)
{
    Fixed   Area = (((one.getX() * two.getY() + two.getX() * three.getY() + three.getX() * one.getY()) -
                    (one.getX() * three.getY() + three.getX() * two.getY() + two.getX() * one.getY())) / 2);
    if (Area < 0)
        Area = Area * (-1);
    if (Area == 0)
        Area = -1;
    return (Area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{    
    Fixed   areaABC = getArea(a, b, c);
    Fixed   areaABP = getArea(a, b, point);
    Fixed   areaBCP = getArea(b, c, point);
    Fixed   areaACP = getArea(a, c, point);

    if (areaABC == areaABP + areaACP + areaBCP)
        return (true);
    else
        return (false);
}
