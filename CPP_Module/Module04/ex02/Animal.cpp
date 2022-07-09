/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:52:40 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 16:10:06 by acaravan         ###   ########.fr       */
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

const std::string	Animal::getType() const
{
	return (type);
}
