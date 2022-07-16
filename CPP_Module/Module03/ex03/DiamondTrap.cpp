/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:31:26 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/16 19:32:50 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){}

DiamondTrap::DiamondTrap(const std::string &Name) :	ScavTrap(Name),
													FragTrap(Name),
													_Name(Name)
{
	std::cout << "DIAMONDTRAP constructor called" << std::endl;
	setHitpoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap) :
_Name(diamondtrap._Name)
{

}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &diamondtrap) const
{
	DiamondTrap *copy = new DiamondTrap(diamondtrap);
	return (*copy);
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}
