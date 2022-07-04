/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 01:47:10 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/03 20:00:58 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string const &name)
{
	_name = name;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weaponB = &weapon;
}

void	HumanB::attack()
{
	std::cout << _name << " attacks with his " << _weaponB->getType() << std::endl;
}

std::string	HumanB::getName() const
{
	return(_name);
}

void	HumanB::setName(const std::string &name)
{
	_name = name;
}
