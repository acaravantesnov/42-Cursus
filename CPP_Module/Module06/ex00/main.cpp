/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:26:01 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/19 19:34:51 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

bool	isNumber(const std::string &str);
int		extreme_cases(const std::string &str);
int		str_is_char(const std::string &str);
int		negative_number(const std::string &str);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error." << std::endl;
		return (1);
	}

	std::string	str(argv[1]);

	if ((str.length() == 0) || (str == ".f"))
	{
		std::cout << "Error." << std::endl;
		return (1);
	}

	if ((str.length() == 1) && !(std::isdigit(argv[1][0])))
		return (str_is_char(str));

	if ((str  == "nan") || (str  == "-inf") || (str  == "+inf"))
		return (extreme_cases(str));

	if ((str[0] == '-') && (str.length() > 1))
		return (negative_number(str));

	if (!(isNumber(str)))
	{
		std::cout << "Error." << std::endl;
		return (1);
	}

	int i;
	try
	{
		i = std::stoi(str);
	}
	catch(std::exception &e)
	{
		std::cout << "Number out of range." << std::endl;
		exit(1);
	}
	float	f = std::stof(str);
	char	c = static_cast<char>(i);
	double	d = static_cast<double>(f);

	std::cout << "char: ";
	if ((c >= 32) && (c <= 126))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

bool	isNumber(const std::string &str)
{
	short	n_of_dots = 0;
	short	n_of_f = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		if ((std::isdigit(str[i]) == 0) && (str[i] != '.') && (str[i] != 'f'))
			return (false);
		if (str[i] == '.')
			n_of_dots++;
		if (str[i] == 'f')
			n_of_f++;
	}
	if ((n_of_dots > 1) || (n_of_f > 1))
		return (false);
	return (true);
}

int	extreme_cases(const std::string &str)
{
	if (str == "nan") 
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
	return (0);
}

int		str_is_char(const std::string &str)
{
	std::cout << "char: ";
	if ((str[0] >= 32) && (str[0] <= 126))
		std::cout << "'" << str[0] << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "int: " << int(str[0]) << std::endl;
	std::cout << "float: " << int(str[0]) << ".0f" << std::endl;
	std::cout << "double: " << int(str[0]) << ".0" << std::endl;
	return (0);
}

int		negative_number(const std::string &str)
{
	int i;
	try
	{
		i = std::stoi(str);
	}
	catch(std::exception &e)
	{
		std::cout << "Number out of range." << std::endl;
		exit(1);
	}
	float	f = std::stof(str);
	double	d = static_cast<double>(f);

	std::cout << "char: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
	return (0);
}