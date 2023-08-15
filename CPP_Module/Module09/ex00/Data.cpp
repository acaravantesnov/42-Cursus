/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:22:04 by acaravan          #+#    #+#             */
/*   Updated: 2023/08/15 13:33:32 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{}

Data::Data(const std::string date, const float value) : _date(date), _value(value)
{}

Data::~Data()
{}

Data &Data::operator=(Data &data)
{
    if (this != &data)
    {
        this->_date = data.getDate();
        this->_value = data.getValue();
    }
    return (*this);
}

std::string   Data::getDate() const
{
    return (_date);
}

void Data::setDate(std::string date)
{
    _date = date;
}

float Data::getValue() const
{
    return (_value);
}

void Data::setValue(float value)
{
    _value = value;
}
