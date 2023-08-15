/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:27:42 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/15 17:38:38 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &data) : \
_date(data.getDate()), _value(data.getValue())
{}

BitcoinExchange::BitcoinExchange(const std::string date, const float value) : \
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

std::string   BitcoinExchange::getDate() const
{
    return (_date);
}

void BitcoinExchange::setDate(std::string date)
{
    _date = date;
}

float BitcoinExchange::getValue() const
{
    return (_value);
}

void BitcoinExchange::setValue(float value)
{
    _value = value;
}
