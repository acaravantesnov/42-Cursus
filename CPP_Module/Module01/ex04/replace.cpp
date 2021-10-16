/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 03:36:17 by acaravan          #+#    #+#             */
/*   Updated: 2021/10/08 18:59:46 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

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

void	Replace::replace()
{
	std::string		text;
	std::string		*aux = &text;
	int				pos;
	std::ifstream	fileRead;
	std::ofstream	fileWrite;
	fileRead.open(_fileName, std::ios::in);
	fileWrite.open(_fileName + ".replace", std::ios::out);
	std::getline (fileRead, text, '\0');
	std::cout << text.find(_s1) << std::endl;
	if ((text.find(_s1) < 0) || (text.find(_s1) >= text.length()))
		fileWrite << text;
	/*else if ((_s2.find(_s1) >= 0) && (_s2.find(_s1) <= _s2.length()))
	{

	}*/
	else
	{
		pos = text.find(_s1);
		while((pos >= 0) && ((unsigned long)pos <= text.length()))
		{
			text.erase(pos, _s1.length());
			text.insert(pos, _s2);
			pos = text.find(_s1);
		}
		fileWrite << *aux;
	}
	std::cout << *aux << std::endl;
}
