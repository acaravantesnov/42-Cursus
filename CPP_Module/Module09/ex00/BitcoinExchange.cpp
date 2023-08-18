/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:27:42 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/18 20:07:52 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &data) : \
_date(data.getDate()), _value(data.getValue())
{}

BitcoinExchange::BitcoinExchange(const std::list<std::string> date, const std::list<float> value) : \
_date(date), _value(value)
{}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &data)
{
    if (this != &data)
    {
        this->_date = data.getDate();
        this->_value = data.getValue();
    }
    return (*this);
}

int BitcoinExchange::compareNext(int y2, int m2, int d2, int y3, int m3, int d3)
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

void BitcoinExchange::pushData(std::string date, float value)
{
    _date.push_back(date);
    _value.push_back(value);
}

void BitcoinExchange::processDataFile(int argc)
{
	std::ifstream	datafile;
	std::string		line;

    if (argc != 2)
		throw(InvalidNumberofArgs());

	// Storing data.csv into array data[nlines - 1]
	datafile.open("data.csv", std::ios::in);
	if (datafile.fail())
		throw (DataFileMissing());
	getline(datafile, line);
	while (getline(datafile, line))
		pushData(line.substr(0, line.find(",")), stof(line.substr(11)));
	datafile.close();
}

void BitcoinExchange::processInputFile(std::string argv1)
{
    std::ifstream	inputfile;
    std::string     line;

    std::string date;
    float       number, value, realValue;


    inputfile.open(argv1, std::ios::in);
	if (inputfile.fail())
		throw (InputFileMissing());
    getline(inputfile, line);
	while (getline(inputfile, line))
	{
		if (line.find(" | ") == std::string::npos)
			std::cout << "Error: bad input => " << line << std::endl;
		else
		{
			date = line.substr(0, line.find(" | "));
			number = stof(line.substr(line.find(" | ") + 3));

            std::list<std::string>::iterator it = _date.begin();
			std::istringstream ss1(*it);
			std::istringstream ss2(date);
			std::istringstream ss3(*std::next(it));

			int year1, month1, day1;
			int year2, month2, day2;
			int year3, month3, day3;
			char dash1, dash2;

			ss1 >> year1 >> dash1 >> month1 >> dash2 >> day1;
			ss2 >> year2 >> dash1 >> month2 >> dash2 >> day2;
			ss3 >> year3 >> dash1 >> month3 >> dash2 >> day3;

			while(1)
			{
				if (it == _date.end())
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
				std::istringstream ss1(*it);
				ss1 >> year1 >> dash1 >> month1 >> dash2 >> day1;
				std::istringstream ss3(*std::next(it));
				ss3 >> year3 >> dash1 >> month3 >> dash2 >> day3;
			}
            int index = std::distance(_date.begin(), it);
            std::list<float>::iterator itValue = _value.begin();
			if (it != _date.end())
				value = *std::next(itValue, index);
			else
				value = *std::prev(std::next(itValue, index));
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
}


std::list<std::string> BitcoinExchange::getDate() const
{
    return (_date);
}

void BitcoinExchange::setDate(std::list<std::string> date)
{
    _date = date;
}

std::list<float> BitcoinExchange::getValue() const
{
    return (_value);
}

void BitcoinExchange::setValue(std::list<float> value)
{
    _value = value;
}

const char *BitcoinExchange::InvalidNumberofArgs::what() const throw()
{
    return ("Invalid number of arguments.");
}

const char *BitcoinExchange::DataFileMissing::what() const throw()
{
    return ("data.csv file missing.");
}

const char *BitcoinExchange::InputFileMissing::what() const throw()
{
    return ("Input file missing.");
}
