/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:12:47 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 17:24:58 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template<typename T>
void	easyfind(const T &container, int n)
{
	container::iterator	it;
	container::iterator	ite = container.end();

	for (it = container.begin(); it != ite; it++)
	{
		if (container[it] == n)
			return (n);
	}
	return (-1);
}

#endif
