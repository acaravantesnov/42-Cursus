/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:13:09 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/22 13:48:38 by acaravan         ###   ########.fr       */
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
	this->_Brainptr = new Brain;
	*this = dog;
}

Dog::~Dog()
{
	delete (_Brainptr);
	std::cout << "Dog destructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &dog)
{
	if (this != &dog)
	{
		std::cout << "Assignment operator called" << std::endl;
		this->type = dog.type;
		delete (_Brainptr);
		this->_Brainptr = new Brain;
		for (int i = 0; i < 100; i++)
			this->_Brainptr->getideas()[i] = dog._Brainptr->getideas()[i];
	}
	return (*this);
}

Brain*			Dog::getBrainptr() const
{
	return (_Brainptr);
}

void	Dog::makeSound() const
{
	std::cout << "Guau" << std::endl;
}
