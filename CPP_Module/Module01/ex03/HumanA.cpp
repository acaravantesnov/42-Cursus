/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:46:42 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/29 15:54:42 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon): _weaponA(weapon)
{
	_name = name;
}

void	HumanA::attack()
{
	std::cout << _name << " attacks with his " << _weaponA.getType() << std::endl;
}

std::string	&HumanA::getName()
{
	return(_name);
}

void	HumanA::setName(const std::string &name)
{
	_name = name;
}
