/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by acaravan          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{}

Point::Point(const float &x, const float &y) : _x(x), _y(y)
{}

Point::Point(const Point &point) : _x(point._x), _y(point._y)
{}

Point::~Point()
{}

Point	&Point::operator=(const Point &point)
{
	if (this != &point) {
        (Fixed)this->_x = point.getX();
        (Fixed)this->_y = point.getY();
    }
    return (*this);
}

Fixed	Point::getX() const
{
	return (this->_x);
}

Fixed	Point::getY() const
{
	return (this->_y);
}
