/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:43:12 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/23 00:21:47 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*-----------------ex00-----------------*/

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = f.getRawBits();
}

void	Fixed::operator=(const Fixed &f2)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_value = f2.getRawBits();
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

/*-----------------ex01-----------------*/

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floating_point)
{
	std::cout << "Float constructor called" << std::endl;
}

float	Fixed::toFloat( void ) const
{

}

int		Fixed::toInt( void ) const
{

}

std::ostream	&operator<<(std::ostream &stream, Fixed &f)
{

	return (stream);
}
