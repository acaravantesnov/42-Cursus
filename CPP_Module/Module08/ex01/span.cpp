/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:11:37 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/18 19:24:47 by acaravan         ###   ########.fr       */
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
	unsigned int	sS;
	if (_index < 2)
		throw (std::exception());
	else
	{
		sS = INT_MAX;
		std::sort(_integers.begin(), _integers.end());
		for (std::vector<int>::iterator it = _integers.begin(); \
		it != (_integers.end() - 1); it++)
		{
			if ((*(it + 1) - *it) < sS)
				sS = *(it + 1) - *it;
		}
	}
	return (sS);
}

unsigned int	Span::longestSpan()
{
	unsigned int	lS;
	if (_index < 2)
		throw (std::exception());
	else
	{
		lS = 0;
		std::sort(_integers.begin(), _integers.end());
		std::vector<int>::iterator	itb = _integers.begin();
		std::vector<int>::iterator	ite = _integers.end();
		lS = *(ite - 1) - *itb;
	}
	return (lS);
}