/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:53:02 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 17:17:38 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	type = "ice";
}

Ice::Ice(Ice &ice)
{
	this->type = ice.type;
}

Ice::~Ice()
{
	
}

AMateria* Ice::clone() const
{
	
}

void Ice::use(ICharacter& target)
{
	
}