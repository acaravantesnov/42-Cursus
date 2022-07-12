/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:12:47 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/13 00:57:24 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	return (std::find(container.begin(), container.end(), value));
}

#endif
