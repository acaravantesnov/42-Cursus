/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:21:26 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/03 19:48:17 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	s = "HI THIS IS BRAIN";
	std::string *stringPTR = &s;
	std::string &stringREF = s;

	std::cout << "Memory address of string: " << &s << std::endl;
	std::cout << "Memory address of string: " << stringPTR << std::endl;
	std::cout << "Memory address of string: " << &stringREF << std::endl;

	std::cout << "String: " << s << std::endl;
	std::cout << "String: " << *stringPTR << std::endl;
	std::cout << "String: " << stringREF << std::endl;
}
