/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:12:44 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/13 00:58:53 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

#define N 10

int	main(void)
{
	std::vector<int> container;
	for (int i = 0; i < N; i++)
		container.push_back(i);
	int result = easyfind(&container, 5);
	std::cout << result << std::endl;
	return (0);
}