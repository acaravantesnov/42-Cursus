/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:13:09 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/18 16:11:46 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	this->_Brainptr = new Brain;
}

Dog::Dog(Dog &dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = dog;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete (_Brainptr);
}

Dog	&Dog::operator=(Dog const &dog)
{
	if (this != &dog)
	{
		std::cout << "Assignment operator called" << std::endl;
		this->type = dog.type;
		this->_Brainptr = new Brain;
		for (int i = 0; i < 100; i++)
			this->_Brainptr->ideas[i] = dog._Brainptr->ideas[i];
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Guau" << std::endl;
}
