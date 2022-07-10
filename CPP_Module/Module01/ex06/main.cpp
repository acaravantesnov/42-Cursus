/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:02:03 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 19:20:14 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int	getLevel(const std::string argv_str)
{
	if (argv_str.compare("DEBUG") == 0)
		return (0);
	if (argv_str.compare("INFO") == 0)
		return (1);
	if (argv_str.compare("WARNING") == 0)
		return (2);
	if (argv_str.compare("ERROR") == 0)
		return (3);
	return (4);
}

int	main(int argc, char **argv)
{
	Karen	karen;
	if (argc != 2)
		return (1);
	std::string	argv_str(argv[1]);
	int level = getLevel(argv_str);
	switch (level)
	{
		case (0):
			karen.complain("DEBUG");
			karen.complain("INFO");
			karen.complain("WARNING");
			karen.complain("ERROR");
			break;
		case (1):
			karen.complain("INFO");
			karen.complain("WARNING");
			karen.complain("ERROR");
			break;
		case (2):
			karen.complain("WARNING");
			karen.complain("ERROR");
			break;
		case (3):
			karen.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << \
			std::endl;
			break;
	}
}
