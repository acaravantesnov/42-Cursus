/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:23:44 by acaravan          #+#    #+#             */
/*   Updated: 2023/03/20 15:31:06 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	std::string arguments;

	if (argc != 2)
	{
		std::cout << "Error: Wrong number of arguments." << std::endl;
		return (1);
	}
	arguments = argv[1];
	return (0);
}
