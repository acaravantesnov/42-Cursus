/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:43:12 by acaravan          #+#    #+#             */
/*   Updated: 2024/06/11 20:21:23 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*-----------------ex00-----------------*/

Fixed::Fixed() : _RawBits(0)
{}

Fixed::Fixed(const Fixed &f)
{
	this->setRawBits(f.getRawBits());
}

Fixed::~Fixed()
{}

Fixed	&Fixed::operator=(const Fixed &f2)
{
	this->setRawBits(f2.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (_RawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_RawBits = raw;
}

/*-----------------ex01-----------------*/

Fixed::Fixed(const int integer)
{
	this->_RawBits = (integer << Fixed::_bits);
}

Fixed::Fixed(const float floating_point)
{
	this->_RawBits = std::roundf(floating_point * (1 << Fixed::_bits));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_RawBits / (float)(1 << Fixed::_bits));
}

int		Fixed::toInt(void) const
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
	this->_RawBits += f.getRawBits();
	return (*this);
}

Fixed	Fixed::operator-(Fixed const &f)
{
	this->_RawBits -= f.getRawBits();
	return (*this);
}

Fixed	Fixed::operator*(Fixed const &f)
{
	this->_RawBits = (this->toFloat() * f.toFloat()) * (1 << _bits);
	return (*this);
}

Fixed	Fixed::operator/(Fixed const &f)
{
	this->_RawBits = (this->toFloat() / f.toFloat()) * (1 << _bits);
	return (*this);
}

Fixed	Fixed::operator++() //Pre-increment
{
	this->_RawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int) //Post-increment
{
	Fixed	temp(*this);
	++(*this);
	return (temp);
}

Fixed	Fixed::operator--() //Pre-decrement
{
	this->_RawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int) //Post-decrement
{
	Fixed	temp(*this);
	--(*this);
	return (temp);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}


