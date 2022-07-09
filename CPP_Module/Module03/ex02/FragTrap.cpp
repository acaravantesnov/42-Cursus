/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:01:46 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 18:32:36 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	ClapTrap();
	std::cout << "Default FRAGTRAP constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &Name) : ClapTrap(Name)
{
	std::cout << "FRAGTRAP constructor called" << std::endl;
	setHitpoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(FragTrap &fragTrap)
{
	std::cout << "FRAGTRAP copy constructor called" << std::endl;
	*this = fragTrap;
}

FragTrap::~FragTrap()
{
	std::cout << "FRAGTRAP destructor called" << std::endl;
	ClapTrap::~ClapTrap();
}

FragTrap	&FragTrap::operator=(FragTrap &fragTrap2)
{
	if (this != &fragTrap2)
	{
		std::cout << "FRAGTRAP assignation operator called" << std::endl;
		this->setName(fragTrap2.getName());
		this->setHitpoints(fragTrap2.getHitpoints());
		this->setEnergyPoints(fragTrap2.getEnergyPoints());
		this->setAttackDamage(fragTrap2.getAttackDamage());
	}
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "HIGH FIVES GUYS!" << std::endl;
}
