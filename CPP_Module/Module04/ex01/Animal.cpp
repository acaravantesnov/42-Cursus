/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:52:40 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/18 16:47:43 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal &animal)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = animal.type;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal	&Animal::operator=(Animal const &animal)
{
	if (this != &animal)
	{
		std::cout << "Assignation operator called" << std::endl;
		this->type = animal.getType();
	}
	return (*this);
}

const std::string	Animal::getType() const
{
	return (type);
}

void				Animal::setType(std::string type)
{
	this->type = type;
}

void	Animal::makeSound() const
{
	std::cout << "Just an animal" << std::endl;
}
