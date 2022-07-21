/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:13:31 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/21 16:23:50 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _Name(""), _Inventory()
{

}

Character::Character(Character const &character) :	_Name(character.getName())
{
	*this = character;
}

Character::Character(const std::string &name) :	_Name(name),
												_Inventory(),
												_index(0)
{

}

Character::~Character()
{
	for (int i = 0; i < _index; i++)
		delete (_Inventory[i]);
}

Character	&Character::operator=(Character const &character)
{
	if (this != &character)
	{
		this->_index = character._index;
		for (int i = 0; i < _index; i++)
			delete (this->_Inventory[i]);
		for (int i = 0; i < _index; i++)
			this->_Inventory[i] = character._Inventory[i]->clone();
	}
	return (*this);
}

std::string	const &Character::getName() const
{
	return (_Name);
}

void Character::equip(AMateria* m)
{
	if (_index < 4)
	{
		this->_Inventory[_index] = m->clone();
		_index++;
	}
}

void Character::unequip(int idx)
{
	for (int i = idx; i < _index - idx; i++)
		this->_Inventory[idx] = this->_Inventory[idx + 1];
	_index--;
}

void Character::use(int idx, ICharacter& target)
{
	if ((idx < _index) && (idx >= 0))
		this->_Inventory[idx]->use(target);
}
