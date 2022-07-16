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
{
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float &x, const float &y) : _x(x), _y(y)
{
	std::cout << "Parameter constructor called" << std::endl;
}

Point::Point(const Point &point) : _x(point._x), _y(point._y)
{
	std::cout << "Copy constructor called" << std::endl;
}

Point::~Point()
{
	std::cout << "Destructor called" << std::endl;
}

Point	&Point::operator=(const Point &point)
{
	std::cout << "Assignation operator called" << std::endl;
	Point	p(point._x.toFloat(), point._y.toFloat());
	return (p);
}

Fixed	Point::getX() const
{
	return (_x);
}

Fixed	Point::getY() const
{
	return (_y);
}
