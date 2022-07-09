/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:12:50 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 21:14:28 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	this->_Brainptr = new Brain;
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete (_Brainptr);
}

Cat::Cat(Cat &cat)
{
	this->type = cat.type;
	this->_Brainptr = new Brain;
	for (int i = 0; i < 100; i++)
		this->_Brainptr->ideas[i] = cat._Brainptr->ideas[i];
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
