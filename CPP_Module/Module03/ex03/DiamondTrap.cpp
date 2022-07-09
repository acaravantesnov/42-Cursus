/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:31:26 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 18:34:18 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){}

DiamondTrap::DiamondTrap(const std::string &Name) :	ClapTrap(Name + "_clap_name"),
													ScavTrap(Name),
													FragTrap(Name),
													_Name(Name)
{
	std::cout << "DIAMONDTRAP constructor called" << std::endl;
	setHitpoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}
