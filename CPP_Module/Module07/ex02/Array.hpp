/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:29:27 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 15:19:06 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class	Array
{
	private:
		T	*_arr;
		int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &array);
		~Array();
		Array<T>	&operator=(const Array<T> &array);
};

template<typename T>
Array<T>::Array() : _size(0), _arr(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _arr(new T[n]) {}

template<typename T>
Array<T>::Array(const Array<T> &array) : _size(array._size) {*this = array;}

template<typename T>
Array<T>::~Array() {}

template<typename T>
Array<T>	&Array<T>::operator=(const Array<T> &array)
{
	try
	{
		if ((this->_size == array._size) && (this != &array))
		{
			delete[] _arr;
			_arr = new T[_size];
			for (int i = 0; i < _size; i++)
				this->_arr[i] = array._arr[i];
		}	
		else
			throw (std::exception());
	}
	catch (std::exception e)
	{
		std::cout << "Cannot copy different size arrays." << std::endl;
	}
}

#endif
