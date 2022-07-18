/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:12:44 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/18 18:08:18 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

#define N 10

int	main(void)
{
	int result = -1;
	std::vector<int> container;
	srand(time(NULL));

	for (int i = 0; i < N; i++)
		container.push_back(rand()%N);
	for (int i = 0; i < N; i++)
		std::cout << container[i] << " ";
	std::cout << std::endl;
	try
	{
		result = easyfind(container, 5);
	}
	catch (std::exception &e)
	{
		std::cerr << "Value not found" << std::endl;
	}
	std::cout << result << std::endl;
	return (0);
}