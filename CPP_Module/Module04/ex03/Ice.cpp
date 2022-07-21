/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:53:02 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/21 13:48:12 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	type = "ice";
}

Ice::Ice(const Ice &ice)
{
	this->type = ice.type;
}

Ice::~Ice()
{
	
}

Ice	&Ice::operator=(Ice const &ice)
{
	if (this != &ice)
		this->type = ice.type;
	return (*this);
}

AMateria* Ice::clone() const
{
	AMateria* mat = new Ice(*this);
	return (mat);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << \
	std::endl;
}
