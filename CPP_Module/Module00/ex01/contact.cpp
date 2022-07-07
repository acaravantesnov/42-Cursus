/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 23:31:18 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/07 21:16:54 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

std::string &contact::get_firstName()
{
	return (_firstName);
}

std::string &contact::get_lastName() 
{
	return (_lastName);
}

std::string &contact::get_nickName()
{
	return (_nickName);
}

std::string &contact::get_phone()
{
	return (_phone);
}

std::string	&contact::get_darkestSecret()
{
	return (_darkestSecret);
}

void		contact::set_firstName(std::string &firstName)
{
	_firstName = firstName;
}

void		contact::set_lastName(std::string &lastName)
{
	_lastName = lastName;
}

void		contact::set_nickName(std::string &nickName)
{
	_nickName = nickName;
}

void		contact::set_phone(std::string &phone)

{
	_phone = phone;
}

void		contact::set_darkestSecret(std::string &darkestSecret)
{
	_darkestSecret = darkestSecret;
}

contact::contact() {}

contact::contact(std::string firstName, std::string lastName, \
std::string nickName, std::string phone, std::string darkestSecret)
{
	_firstName = firstName;
	_lastName = lastName;
	_nickName = nickName;
	_phone = phone;
	_darkestSecret = darkestSecret;
}
