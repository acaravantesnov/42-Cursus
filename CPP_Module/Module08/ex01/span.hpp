/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:11:40 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/21 16:45:44 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>

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

		void			addNumber(int n);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
};

#endif
