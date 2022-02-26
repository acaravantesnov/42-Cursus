/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:43:12 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/25 21:13:42 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*-----------------ex00-----------------*/

Fixed::Fixed() : _RawBits(0)
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
	this->_RawBits = f.getRawBits();
}

Fixed	Fixed::operator=(const Fixed &f2)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_RawBits = f2.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	return (_RawBits);
}

void	Fixed::setRawBits( int const raw )
{
	this->_RawBits = raw;
}

/*-----------------ex01-----------------*/

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->_RawBits = (integer << Fixed::_bits);
}

Fixed::Fixed(const float floating_point)
{
	std::cout << "Float constructor called" << std::endl;
	this->_RawBits = roundf(floating_point * (1 << Fixed::_bits));
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->_RawBits / (float)(1 << Fixed::_bits));
}

int		Fixed::toInt( void ) const
{
	return (this->_RawBits >> Fixed::_bits);
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &f)
{
	stream << f.toFloat();
	return (stream);
}

/*-----------------ex02-----------------*/

bool	Fixed::operator>(Fixed const &f) const
{
	if (this->_RawBits > f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &f) const
{
	if (this->_RawBits < f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &f) const
{
	if (this->_RawBits >= f.getRawBits())
		return (true);
	return (false);	
}

bool	Fixed::operator<=(Fixed const &f) const
{
	if (this->_RawBits <= f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &f) const
{
	if (this->_RawBits == f.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &f) const
{
	if (this->_RawBits != f.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(Fixed const &f)
{
	this->_RawBits += f._RawBits;
	return (*this);
}

Fixed	Fixed::operator-(Fixed const &f)
{
	this->_RawBits -= f._RawBits;
	return (*this);
}

Fixed	Fixed::operator*(Fixed const &f)
{
	this->_RawBits *= f._RawBits;
	return (*this);
}

Fixed	Fixed::operator/(Fixed const &f)
{
	this->_RawBits /= f._RawBits;
	return (*this);
}

Fixed	Fixed::operator++() //Pre-increment
{
	this->_RawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int) //Post-increment
{
	this->_RawBits++;
	return (*this);
}

Fixed	Fixed::operator--() //Pre-decrement
{
	this->_RawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int) //Post-decrement
{
	this->_RawBits--;
	return (*this);
}