/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:43:14 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/25 11:27:23 by acaravan         ###   ########.fr       */
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
		Fixed(const Fixed &f); //Copy Constructor
		virtual ~Fixed(); //Destructor

		int		getRawBits( void ) const; //Returns the raw value of the fixed point value
		void	setRawBits( int const raw ); //Sets the raw value of the fixed point value.

		Fixed(const int integer);
		Fixed(const float floating_point);
		float	toFloat( void ) const;
		int		toInt( void ) const;

		Fixed	operator=(Fixed const &f2);

		bool	operator>(Fixed const &f) const;
		bool	operator<(Fixed const &f) const;
		bool	operator>=(Fixed const &f) const;
		bool	operator<=(Fixed const &f) const;
		bool	operator==(Fixed const &f) const;
		bool	operator!=(Fixed const &f) const;

		Fixed	operator+(Fixed const &f);
		Fixed	operator-(Fixed const &f);
		Fixed	operator*(Fixed const &f);
		Fixed	operator/(Fixed const &f);

		Fixed	operator++(); //Pre-increment
		Fixed	operator++(int); //Post-increment
		Fixed	operator--(); //Pre-decrement
		Fixed	operator--(int); //Post-decrement

		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
};

std::ostream	&operator<<(std::ostream &stream, Fixed const &f);
Fixed const &min(Fixed const &a, Fixed const &b);
Fixed const &max(Fixed const &a, Fixed const &b);
Fixed &min(Fixed &a, Fixed &b);
Fixed &max(Fixed &a, Fixed &b);

# endif