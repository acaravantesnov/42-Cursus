/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:12:47 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/26 10:13:38 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template<typename T>
int	easyfind(T &t, int value)
{
	typename T::iterator it;
	it = std::find(t.begin(), t.end(), value);
	if (it != t.end())
		return (*it);
	throw (std::exception());
}

#endif
