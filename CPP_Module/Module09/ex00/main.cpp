/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:09:22 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/15 17:30:10 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int compareNext(int y2, int m2, int d2, int y3, int m3, int d3)
{
	if (y2 < y3)
		return (1);
	else if (y2 == y3)
	{
		if (m2 < m3)
			return (1);
		else if (m2 == m3)
		{
			if (d2 < d3)
				return (1);
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	std::vector<BitcoinExchange>			data;
	std::vector<BitcoinExchange>::iterator	it;
	std::ifstream							inputfile, datafile;
	std::string								line, date;
	float									number, value, realValue;

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
	getline(datafile, line);
	while (getline(datafile, line))
		data.push_back(BitcoinExchange(line.substr(0, line.find(",")), stof(line.substr(11))));
	datafile.close();

	inputfile.open(argv[1], std::ios::in);
	if (inputfile.fail())
	{
		std::cout << "Error: Input file missing." << std::endl;
		return (1);
	}
	getline(inputfile, line);
	while (getline(inputfile, line))
	{
		if (line.find(" | ") == std::string::npos)
			std::cout << "Error: bad input => " << line << std::endl;
		else
		{
			date = line.substr(0, line.find(" | "));
			number = stof(line.substr(line.find(" | ") + 3));

			it = data.begin();
			std::istringstream ss1(it->getDate());
			std::istringstream ss2(date);
			std::istringstream ss3((it + 1)->getDate());

			int year1, month1, day1;
			int year2, month2, day2;
			int year3, month3, day3;
			char dash1, dash2;

			ss1 >> year1 >> dash1 >> month1 >> dash2 >> day1;
			ss2 >> year2 >> dash1 >> month2 >> dash2 >> day2;
			ss3 >> year3 >> dash1 >> month3 >> dash2 >> day3;

			while(1)
			{
				if (it == data.end())
					break;
				if (year2 > year1)
				{
					if (compareNext(year2, month2, day2, year3, month3, day3) == 1)
						break;
				}
				else if (year2 == year1)
				{
					if (month2 > month1)
					{
						if (compareNext(year2, month2, day2, year3, month3, day3) == 1)
							break;
					}
					else if (month2 == month1)
					{
						if (day2 >= day1)
							if (compareNext(year2, month2, day2, year3, month3, day3) == 1)
								break;
					}
				}
				it++;
				std::istringstream ss1(it->getDate());
				ss1 >> year1 >> dash1 >> month1 >> dash2 >> day1;
				std::istringstream ss3((it + 1)->getDate());
				ss3 >> year3 >> dash1 >> month3 >> dash2 >> day3;
			}
			if (it != data.end())
				value = (it)->getValue();
			else
				value = (it - 1)->getValue();
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
