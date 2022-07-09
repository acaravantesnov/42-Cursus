/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:52:55 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 17:22:18 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	type = "cure";
}

Cure::Cure(Cure &cure)
{
	this->type = cure.type;
}

Cure::~Cure()
{
	
}

AMateria* Cure::clone() const
{
	AMateria* clone = new AMateria;
	
}

void Cure::use(ICharacter& target)
{
	
}
