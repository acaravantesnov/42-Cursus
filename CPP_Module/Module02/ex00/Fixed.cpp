/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:43:12 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/04 16:16:26 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

void	Fixed::operator=(const Fixed &f2)
{
	std::cout << "Assignation operator called" << std::endl;
	this->setRawBits(f2.getRawBits());
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_RawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_RawBits = raw;
}
