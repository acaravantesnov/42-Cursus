/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:43:14 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/16 22:45:32 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					_RawBits;
		static const int	_bits = 8;
	public:
		Fixed(); //Default Constructor
		~Fixed(); //Destructor
		Fixed(const Fixed &f); //Copy Constructor
		Fixed	&operator=(const Fixed &f2); //= operator overload

		//Returns the raw value of the fixed point value.
		int		getRawBits(void) const;
		//Sets the raw value of the fixed point value.
		void	setRawBits(int const raw);

		Fixed(const int integer);
		Fixed(const float floating_point);

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &stream, Fixed const &f);

# endif