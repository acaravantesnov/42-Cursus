/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:43:03 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/21 14:30:04 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _Stored(), _index(0)
{
	
}

MateriaSource::MateriaSource(MateriaSource const &materiasource)
{
	*this = materiasource;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _index; i++)
		delete (this->_Stored[i]);
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &materiasource)
{
	if (this != &materiasource)
	{
		this->_index = materiasource._index;
		for (int i = 0; i < _index; i++)
			delete (this->_Stored[i]);
		for (int i = 0; i < _index; i++)
			this->_Stored[i] = materiasource._Stored[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	this->_Stored[_index] = m->clone();
	_index++;
}

AMateria*		MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _index; i++)
		if (this->_Stored[i]->getType() == type)
			return (this->_Stored[i]->clone());
	return (0);
}
