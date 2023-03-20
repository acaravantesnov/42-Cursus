/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:09:22 by acaravan          #+#    #+#             */
/*   Updated: 2023/03/20 01:35:35 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::vector<t_data>				data; // Using vector, but can be changed by array or list.
	std::vector<t_data>::iterator	it;
	std::ifstream					inputfile, datafile;
	std::string						line, date;
	float							number, value, realValue;

	if (argc != 2)
	{
		std::cout << "Error: Wrong number of arguments." << std::endl;
		return (1);
	}

	// Storing data.csv into array data[nlines - 1]
	datafile.open("data.csv", std::ios::in);
	if (datafile.fail())
	{
		std::cout << "Error: data.csv file missing." << std::endl;
		return (1);
	}
	getline(datafile, line); //Just to forget about first line.
	while (getline(datafile, line))
		data.push_back(t_data(	line.substr(0, line.find(",")), \
								stof(line.substr(11))));
	datafile.close();


	inputfile.open(argv[1], std::ios::in);
	if (inputfile.fail())
	{
		std::cout << "Error: Input file missing." << std::endl;
		return (1);
	}
	getline(inputfile, line);  //Just to forget about first line.
	while (getline(inputfile, line))
	{
		if (line.find(" | ") == std::string::npos) // Need to add better parsing
			std::cout << "Error: bad input => " << line << std::endl;
		else
		{
			date = line.substr(0, line.find(" | "));
			number = stof(line.substr(line.find(" | ") + 3));
			for (it = data.begin(); it->date < date; it++);
			value = it->value;
			realValue = number * value;
			if (number < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (number > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else
				std::cout << line.substr(0, 10) << " => " << \
				line.substr(12) << " = " << realValue << std::endl;
		}
	}
	inputfile.close();

	return (0);
}
