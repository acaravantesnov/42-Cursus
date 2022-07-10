/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:56:53 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 14:28:05 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
T	iter(T *arr, int len, void (*funcptr)(T))
{
	for (int i = 0; i < len; i++)
		funcptr(arr[i]);
	return (*arr);
}

#endif
