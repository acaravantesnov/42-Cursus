/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:12:47 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/18 18:06:04 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

template<typename T>
int	easyfind(T &t, int value)
{
	typename T::iterator element;
	element = std::find(t.begin(), t.end(), value);
	if (element != t.end())
		return (*element);
	throw (std::exception());
}

#endif
