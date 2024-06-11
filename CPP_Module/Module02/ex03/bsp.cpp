/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by acaravan          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed abs (Fixed x)
{
	if (x >= 0)
		return (x);
	return (x * -1);
}

Fixed area( Point const a, Point const b, Point const c )
{
	Fixed sum = a.getX() * (b.getY() - c.getY()) + \
	b.getX() * (c.getY() - a.getY()) + \
	c.getX() * (a.getY() - b.getY());
	return (abs(sum) / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed abcArea = area(a, b ,c);
	Fixed pabArea = area(point, a, b);
	Fixed pacArea = area(point, a, c);
	Fixed pbcArea = area(point, b, c);
	
	if ((pabArea == 0) || (pacArea == 0) || (pbcArea == 0))
		return (0);
	return (abcArea == (pabArea + pacArea + pbcArea));
}
