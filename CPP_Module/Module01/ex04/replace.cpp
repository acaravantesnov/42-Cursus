/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 03:36:17 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/04 15:45:35 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

Replace::Replace() {}

Replace::Replace(const std::string &fileName, const std::string &s1, \
const std::string &s2)
{
	std::cout << "Created object!" << std::endl;
	_fileName = fileName;
	_s1 = s1;
	_s2 = s2;
}

Replace::~Replace()
{
	std::cout << "Destroyed object!" << std::endl;
}

int	Replace::replace()
{
	std::string		line;
	std::string		*aux = &line;
	int				pos;
	std::ifstream	fileRead;
	std::ofstream	fileWrite;

	if ((_s1 == _s2) || (_s1 == "") || (_s2 == ""))
		return (1);
	fileRead.open(_fileName, std::ios::in);
	if (!(fileRead.good()))
		return (1);
	fileWrite.open(_fileName + ".replace", std::ios::out);
	if (!(fileWrite.good()))
		return (1);
	std::getline (fileRead, line, '\0');
	if (line.find(_s1) == std::string::npos)
		fileWrite << line;
	else
	{
		pos = line.find(_s1);
		while(pos != std::string::npos)
		{
			line.erase(pos, _s1.length());
			line.insert(pos, _s2);
			pos = line.find(_s1, pos + _s2.length());
		}
		fileWrite << *aux;
	}
	std::cout << *aux << std::endl;
	return (0);
}
