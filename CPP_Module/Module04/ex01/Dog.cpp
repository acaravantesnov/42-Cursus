/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:13:09 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/18 15:05:05 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(Dog &dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = dog.type;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &dog)
{
	if (this != &dog)
	{
		std::cout << "Assignment operator called" << std::endl;
		this->type = dog.getType();
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Guau" << std::endl;
}
