/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:11:33 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/26 11:15:22 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << std::endl;

	srand(time(NULL));
	Span				vec(100);
	std::vector<int>	aux;
	for (int i = 0; i < 100; i++)
		aux.push_back((rand() % 1000000) + 1);
	vec.addNumbers(aux.begin(), aux.end());
	try { vec.addNumber(0); }
	catch (std::exception e) { std::cout << "Error" << std::endl; }

	std::cout << std::endl;

	std::cout << vec.longestSpan() << std::endl;
	std::cout << vec.shortestSpan() << std::endl;

	std::cout << std::endl;

	std::cout << vec;

	std::cout << std::endl;

	srand(time(NULL));
	Span				vec2(10000);
	std::vector<int>	aux2;
	for (int i = 0; i < 10000; i++)
		aux2.push_back((rand() % 10000) + 1);
	vec2.addNumbers(aux2.begin(), aux2.end());

	std::cout << std::endl;

	std::cout << vec2.longestSpan() << std::endl;
	std::cout << vec2.shortestSpan() << std::endl;

	std::cout << std::endl;

	return (0);
}
