/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 03:36:17 by acaravan          #+#    #+#             */
/*   Updated: 2022/04/10 03:29:42 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

Replace::Replace() {}

Replace::Replace(const std::string &fileName, const std::string &s1, const std::string &s2)
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
	std::string		text;
	std::string		text_copy;
	std::string		*aux = &text;
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
	std::getline (fileRead, text, '\0');
	text_copy = text;
	if ((text.find(_s1) < 0) || (text.find(_s1) >= text.length()))
		fileWrite << text;
	else
	{
		pos = text.find(_s1);
		while((pos >= 0) && ((unsigned long)pos <= text.length()))
		{
			text.erase(pos, _s1.length());
			text.insert(pos, _s2);
			text_copy += pos + _s1.length();
			pos = text.find(_s1);
		}
		fileWrite << *aux;
	}
	std::cout << *aux << std::endl;
	return (0);
}
