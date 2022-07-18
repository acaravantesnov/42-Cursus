/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:12:50 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/18 16:59:12 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	this->_Brainptr = new Brain;
}

Cat::Cat(Cat &cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cat;
}

Cat::~Cat()
{
	delete (_Brainptr);
	std::cout << "Cat destructor called" << std::endl;
}

Cat	&Cat::operator=(Cat const &cat)
{
	if (this != &cat)
	{
		std::cout << "Assignment operator called" << std::endl;
		this->type = cat.type;
		delete (_Brainptr);
		this->_Brainptr = new Brain;
		for (int i = 0; i < 100; i++)
			this->_Brainptr->ideas[i] = cat._Brainptr->ideas[i];
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
