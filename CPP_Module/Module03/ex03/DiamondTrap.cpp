/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:31:26 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/20 15:34:26 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _Name("")
{
	std::cout << "Default DIAMONDTRAP constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &Name) :	ClapTrap(Name + "_clap_name"),
													ScavTrap(Name),
													FragTrap(Name),
													_Name(Name)
{
	std::cout << "DIAMONDTRAP constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap) :	ScavTrap(),
															FragTrap(),
															_Name("")
{
	std::cout << "DIAMONDTRAP copy constructor called" << std::endl;
	*this = diamondtrap;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DIAMONDTRAP destructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
	if (this != &diamondtrap)
	{
		std::cout << "FRAGTRAP assignation operator called" << std::endl;
		this->_Name = diamondtrap._Name;
		this->FragTrap::_AttackDamage = diamondtrap.FragTrap::_AttackDamage;
		this->ScavTrap::_EnergyPoints = diamondtrap.ScavTrap::_EnergyPoints;
		this->FragTrap::_Hitpoints = diamondtrap.FragTrap::_Hitpoints;
	}
	return (*this);
}

void	DiamondTrap::attack(std::string const & target)
{
	ScavTrap::setAttackDamage(FragTrap::_AttackDamage);
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	this->_EnergyPoints -= amount;
	std::cout << this->DiamondTrap::getName() << " has lost " \
	<< amount << " healthpoints.. :-(" << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	this->_EnergyPoints += amount;
	std::cout << this->DiamondTrap::getName() << " has recovered " \
	<< amount << " healthpoints. :-)" << std::endl;
}

std::string	&DiamondTrap::getName()
{
	return (this->_Name);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "NAME: " << _Name << std::endl;
	std::cout << "CLAPTRAP NAME: " << this->ClapTrap::getName() << std::endl;
}

std::ostream	&operator<<(std::ostream &stream, DiamondTrap &diamondtrap)
{
	stream << "Name: " << diamondtrap.getName() << \
	" Hitpoints: " << diamondtrap.FragTrap::getHitpoints() << \
	" Energy Points: " << diamondtrap.ScavTrap::getEnergyPoints() << \
	" Attack Damage: " << diamondtrap.FragTrap::getAttackDamage();
	return (stream);
}