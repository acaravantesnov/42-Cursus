/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:57:22 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 03:42:56 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define N 3

int main(void)
{
	std::string	arr[N];
	std::string *arrptr = arr;
	void *ptr = &strlen;
	iter<std::string>(arrptr, N, ptr);
	return (0);
}
