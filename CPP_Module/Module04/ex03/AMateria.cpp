/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:36:26 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/22 13:51:07 by acaravan         ###   ########.fr       */
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
	*this = amateria;
}

AMateria::~AMateria()
{

}

AMateria	&AMateria::operator=(AMateria const &amateria)
{
	if (this != &amateria)
		this->type = amateria.type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
