/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:43:14 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 17:45:43 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					_RawBits;
		static const int	_bits = 8;
	public:
		Fixed(); //Default Constructor
		Fixed(const Fixed &f); //Copy Constructor
		~Fixed(); //Destructor
		//Returns the raw value of the fixed point value
		int		getRawBits( void ) const; 
		//Sets the raw value of the fixed point value.
		void	setRawBits( int const raw ); 
		
		void	operator=(const Fixed &f2); //= operator overload
};

# endif