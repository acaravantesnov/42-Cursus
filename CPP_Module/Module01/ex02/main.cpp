/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:21:26 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/22 20:17:34 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	s = "HI THIS IS BRAIN";
	std::string *stringPTR = &s;
	std::string &stringREF = s;

	std::cout << "Dirección en memoria de la string: " << &s << std::endl;
	std::cout << "Dirección en memoria de la string: " << stringPTR << std::endl;
	std::cout << "Dirección en memoria de la string: " << &stringREF << std::endl;

	std::cout << "String: " << *stringPTR << std::endl;
	std::cout << "String: " << stringREF << std::endl;
}