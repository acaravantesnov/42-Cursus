/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:43:16 by acaravan          #+#    #+#             */
/*   Updated: 2024/06/11 20:38:05 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main()
{
	Point a(0, 0);
	Point b(10, -30);
	Point c(20, 0);
	Point point(5.05, -15);

	std::cout << bsp(a, b, c, point) << std::endl;
	
	return (0);
}
