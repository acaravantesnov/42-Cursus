/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:52:44 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/22 13:39:41 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &wrongcat)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = wrongcat;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &wrongcat)
{
	std::cout << "Assignment operator called" << std::endl;
	this->type = wrongcat.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Meaouw" << std::endl;
}
