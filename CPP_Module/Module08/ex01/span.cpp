/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:11:37 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/26 11:17:24 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span() : _index(0)
{

}

Span::Span(unsigned int N) : _max_size(N), _index(0)
{

}

Span::Span(Span const &span)
{
	*this = span;
}

Span::~Span()
{

}

Span	&Span::operator=(Span const &span)
{
	if (this != &span)
	{
		this->_integers = span._integers;
		this->_max_size = span._max_size;
		this->_index = span._index;
	}
	return (*this);
}

std::vector<int>	Span::getIntegers() const
{
	return (_integers);
}

void	Span::addNumber(int n)
{
	if (_index >= _max_size)
		throw (std::exception());
	else
	{
		_integers.push_back(n);
		_index++;
	}
}

unsigned int	Span::shortestSpan()
{
	std::vector<int>	aux = _integers;
	unsigned int		sS;
	if (_index < 2)
		throw (std::exception());
	else
	{
		sS = INT_MAX;
		std::sort(aux.begin(), aux.end());
		for (std::vector<int>::iterator it = aux.begin(); \
		it != (aux.end() - 1); it++)
		{
			if ((*(it + 1) - *it) < static_cast<int>(sS))
				sS = *(it + 1) - *it;
		}
	}
	return (sS);
}

unsigned int	Span::longestSpan()
{
	std::vector<int>	aux = _integers;
	unsigned int		lS;
	if (_index < 2)
		throw (std::exception());
	else
	{
		lS = 0;
		std::vector<int>::iterator	itb = aux.begin();
		std::vector<int>::iterator	ite = aux.end();
		std::sort(itb, ite);
		lS = *(ite - 1) - *itb;
	}
	return (lS);
}

std::ostream	&operator<<(std::ostream &stream, Span &span)
{
	std::vector<int> ints = span.getIntegers();
	std::vector<int>::iterator	itb = ints.begin();
	std::vector<int>::iterator	ite = ints.end();
	stream << "[ ";
	for(; itb != ite; itb++)
		stream << *itb << " ";
	stream << "]" << std::endl;
	return (stream);
}
