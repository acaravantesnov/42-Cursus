/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:46:15 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/29 15:54:52 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string	&Weapon::getType() const
{
	return (_type);
}

void		Weapon::setType(const std::string &ptype)
{
	_type = ptype;
}

Weapon::Weapon()
{
	
}

Weapon::Weapon(const std::string &type)
{
	_type = type;
}
