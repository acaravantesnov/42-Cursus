/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:29:27 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/20 22:43:33 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

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

		T			&operator[](int) const;
		int			size() const;

		class	OutofBounds : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	DifferentSizeArrays : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

template<typename T>
Array<T>::Array() : _size(0), _arr(new T[0]) {}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _arr(new T[n]) {}

template<typename T>
Array<T>::Array(const Array<T> &array) : _size(array._size)
{
	this->_arr = new T[0];
	*this = array;
}

template<typename T>
Array<T>::~Array() {}

template<typename T>
Array<T>	&Array<T>::operator=(const Array<T> &array)
{
	if (this != &array)
	{
		if (this->_size == array._size)
		{
			delete[] _arr;
			_arr = new T[_size];
			for (int i = 0; i < _size; i++)
				this->_arr[i] = array._arr[i];
		}
		else
			throw (DifferentSizeArrays());
	}
	return (*this);
}

template<typename T>
T	&Array<T>::operator[](int index) const
{
	if ((index >= 0) && (index < _size))
		return (_arr[index]);
	throw (OutofBounds());
}

template<typename T>
int	Array<T>::size() const {return (_size);}

template<typename T>
const char*	Array<T>::OutofBounds::what() const throw()
{
	return ("Cannot access an invalid index.");
}

template<typename T>
const char*	Array<T>::DifferentSizeArrays::what() const throw()
{
	return ("Cannot copy different size arrays.");
}

template<typename T>
std::ostream &operator<<(std::ostream &stream, const Array<T> &array)
{
	stream << "[ ";
	for(int i = 0; i < array.size(); i++)
		stream << array[i] << " ";
	stream << "]" << std::endl;
	return (stream);
}

#endif
