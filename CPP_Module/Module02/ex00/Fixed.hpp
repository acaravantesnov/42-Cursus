/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:43:14 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/22 21:51:30 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	private:
		int	_fixed;
		static const int	_fractional_bits = 8;
	public:
		Fixed() : _fixed(0) {} //Deefault Constructor
		~Fixed() {} //Destructor
		Fixed(const Fixed &f); //Copy Constructor
		void	operator=(Fixed &f2); //= operator overload
		const	int getRawBits( void ); //Returns the raw value of the fixed point value
		void		setRawBits( int const raw ); //Sets the raw value of the fixed point value.
};

# endif