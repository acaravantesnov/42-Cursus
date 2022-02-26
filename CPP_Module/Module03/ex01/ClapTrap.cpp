/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 01:32:24 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/26 04:37:09 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :	_Name(""), 
						_Hitpoints(10), 
						_EnergyPoints(10), 
						_AttackDamage(0)
{
	std::cout << "DEFAULT CLAPTRAP CONSTRUCTOR CALLED" << std::endl;
}

ClapTrap::ClapTrap(std::string Name) :  _Name(Name), 
										_Hitpoints(10),
										_EnergyPoints(10), 
										_AttackDamage(0)
{
	std::cout << "CLAPTRAP CONSTRUCTOR CALLED" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &clapTrap)
{
	std::cout << "CLAPTRAP COPY CONSTRUCTOR CALLED" << std::endl;
	*this = clapTrap;
}

ClapTrap::~ClapTrap()
{	
	std::cout << "CLAPTRAP DESTRUCTOR CALLED" << std::endl;
}

std::string	&ClapTrap::getName() {return (_Name);}
void		ClapTrap::setName(std::string &Name) {_Name = Name;}
int			&ClapTrap::getHitpoints() {return (_Hitpoints);}
void		ClapTrap::setHitpoints(int &Hitpoints) {_Hitpoints = Hitpoints;}
int			&ClapTrap::getEnergyPoints() {return (_EnergyPoints);}
void		ClapTrap::setEnergyPoints(int &EnergyPoints) {_EnergyPoints = EnergyPoints;}
int			&ClapTrap::getAttackDamage() {return (_AttackDamage);}
void		ClapTrap::setAttackDamage(int &AttackDamage) {_AttackDamage = AttackDamage;}

ClapTrap	&ClapTrap::operator=(ClapTrap const &clapTrap2)
{
	if (this != &clapTrap2)
	{
		std::cout << "CLAPTRAP ASSIGNATION OPERATOR CALLED" << std::endl;
		this->_Name = clapTrap2._Name;
		this->_Hitpoints = clapTrap2._Hitpoints;
		this->_EnergyPoints = clapTrap2._EnergyPoints;
		this->_AttackDamage = clapTrap2._AttackDamage;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, ClapTrap const &clapTrap)
{
	stream << "Name: " << clapTrap._Name << \
	" Hitpoints: " << clapTrap._Hitpoints << \
	" Energy Points: " << clapTrap._EnergyPoints << \
	" Attack Damage: " << clapTrap._AttackDamage;
	return (stream);
}

void	ClapTrap::attack(std::string const & target) 
{
	std::cout << this->getName() << " has attacked " << target << ", " \
	<< "causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_EnergyPoints -= amount;
	std::cout << this->getName() << " has lost " \
	<< amount << " healthpoints.. :-(" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_EnergyPoints += amount;
	std::cout << this->getName() << " has recovered " \
	<< amount << " healthpoints. :-)" << std::endl;
}
