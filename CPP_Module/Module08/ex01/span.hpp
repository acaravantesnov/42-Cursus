/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:11:40 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/26 11:17:57 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <iostream>

class	Span
{
	private:
		std::vector<int>	_integers;
		unsigned int		_max_size;
		unsigned int		_index;
	public:
		Span();
		Span(unsigned int N);
		Span(Span const &span);
		~Span();
		Span			&operator=(Span const &span);

		std::vector<int>	getIntegers() const;
		void				addNumber(int n);

		template<typename T>
		void				addNumbers(T itb, T ite)
		{
			int	copydistance = std::distance(itb, ite);;
			if (_index + copydistance <= _max_size)
			{
				_index += copydistance;
				for (; itb != ite; itb++)
					_integers.push_back(*itb);
			}
			else
				throw (std::exception());
		}

		unsigned int		shortestSpan();
		unsigned int		longestSpan();
};

std::ostream	&operator<<(std::ostream &stream, Span &span);

#endif
