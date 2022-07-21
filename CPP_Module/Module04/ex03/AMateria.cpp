/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:36:26 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/21 13:52:51 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria::AMateria()
{
	
}

AMateria::AMateria(AMateria &amateria)
{
	
}

AMateria::~AMateria()
{
	
}

AMateria	&AMateria::operator=(AMateria const &amateria)
{
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	
}
