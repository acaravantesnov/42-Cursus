/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:29:27 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 14:39:12 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class	Array
{
	private:
		T	*arr;
	public:
		Array() {arr = new[] T;}
		Array(unsigned int n) {arr = new[](n) T;}
		Array(const Array &array);
		~Array();
		Array	&operator=(std::ostream &stream, const Array & array);
};

#endif
