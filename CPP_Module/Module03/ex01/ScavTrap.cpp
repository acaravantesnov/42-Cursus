/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:01:46 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/26 04:42:57 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	ClapTrap();
	std::cout << "DEFAULT SCAVTRAP CONSTRUCTOR CALLED" << std::endl;
}

ScavTrap::ScavTrap(const std::string &Name) : ClapTrap(Name)		
{
	std::cout << "SCAVTRAP CONSTRUCTOR CALLED" << std::endl;
	_Hitpoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &scavTrap)
{
	std::cout << "SCAVTRAP COPY CONSTRUCTOR CALLED" << std::endl;
	*this = scavTrap;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SCAVTRAP DESTRUCTOR CALLED" << std::endl;
	ClapTrap::~ClapTrap();
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap have entered in Gate keeper mode." << std::endl;
}
