/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:23:44 by acaravan          #+#    #+#             */
/*   Updated: 2023/03/20 17:29:30 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	check_args(std::string argv1)
{
	if ((argv1.length() < 1) || (argv1[0] == ' ') || \
	(argv1[argv1.length() - 1] == ' '))
		return (false);
	return (true);
}

int *parse_args(std::string argv1)
{
	int *args;
	size_t		nargs, i;

	i = 0;
	nargs = 0;
	while (i < argv1.length())
	{
		if (argv1[i] == ' ')
			nargs++;
		i++;
	}
	nargs++;
	args = new std::string[nargs];
	i = 0;
	while (i < argv1.length())
	{
		size_t find = argv1.find(" ");
		if (find != std::string::npos)

		i++;
	}

	return (args);
}

int main(int argc, char **argv)
{
	int				*args;
	std::stack<int>	st;

	if (argc != 2)
	{
		std::cout << "Error: Wrong number of arguments." << std::endl;
		return (1);
	}
	else if(!check_args(std::string(argv[1])))
	{
		std::cout << "Error: Wrong input format." << std::endl;
		return (1);
	}
	args = parse_args(std::string(argv[1]));

	int i = 0;
	

	return (0);
}
