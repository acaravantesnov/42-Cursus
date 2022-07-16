/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:43:12 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/15 18:52:06 by acaravan         ###   ########.fr       */
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
	this->setRawBits(f.getRawBits());
}

Fixed	Fixed::operator=(const Fixed &f2)
{
	std::cout << "Assignation operator called" << std::endl;
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

/*
NUMBER 12
integer:	0000 0000 0000 1100
_RawBits:	0000 1100 0000 0000
*/

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(integer << Fixed::_bits);
}

/*NUMBER 12.75
integer:	0000 0000 0000 1100
_RawBits:	x *\
			0000 0001 0000 0000
_RawBits:	0000 1100 1100 0000
*/

Fixed::Fixed(const float floating_point)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(std::roundf(floating_point * (1 << Fixed::_bits)));
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
	Fixed	ret(*this);
	int		temp1, temp2;

	temp1 = this->getRawBits();
	temp2 = f.getRawBits();
	ret.setRawBits(temp1 * temp2 / (1 << Fixed::_bits));
	return (ret);
}

Fixed	Fixed::operator/(Fixed const &f)
{
	Fixed	ret(*this);
	int		temp1, temp2;

	temp1 = this->getRawBits();
	temp2 = f.getRawBits();
	ret.setRawBits(temp1 * (1 << Fixed::_bits) / temp2);
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


