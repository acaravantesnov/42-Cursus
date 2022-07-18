/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:01:46 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/18 15:48:31 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default SCAVTRAP constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &Name) : ClapTrap(Name)
{
	std::cout << "SCAVTRAP constructor called" << std::endl;
	setHitpoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(ScavTrap &scavTrap) : ClapTrap()
{
	std::cout << "SCAVTRAP copy constructor called" << std::endl;
	*this = scavTrap;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SCAVTRAP destructor called" << std::endl;
}

int		&ScavTrap::getEnergyPoints()
{
	return (_EnergyPoints);
}

void	ScavTrap::setEnergyPoints(int EnergyPoints)
{
	this->_EnergyPoints = EnergyPoints;
}

ScavTrap	&ScavTrap::operator=(ScavTrap &scavTrap)
{
	if (this != &scavTrap)
	{
		std::cout << "SCAVTRAP assignation operator called" << std::endl;
		this->setName(scavTrap.getName());
		this->setHitpoints(scavTrap.getHitpoints());
		this->setEnergyPoints(scavTrap.getEnergyPoints());
		this->setAttackDamage(scavTrap.getAttackDamage());
	}
	return (*this);
}

void	ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap " << this->getName() << " has attacked " << target << ", " \
	<< "causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap have entered in Gate keeper mode." << std::endl;
}

