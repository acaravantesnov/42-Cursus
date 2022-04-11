/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:01:46 by acaravan          #+#    #+#             */
/*   Updated: 2022/04/11 13:10:04 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() :	ClapTrap()
{
	std::cout << "DEFAULT FRAGTRAP CONSTRUCTOR CALLED" << std::endl;
}

FragTrap::FragTrap(const std::string &Name) : ClapTrap(Name)
{
	std::cout << "FRAGTRAP CONSTRUCTOR CALLED" << std::endl;
	_Hitpoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &fragTrap)
{
	std::cout << "FRAGTRAP COPY CONSTRUCTOR CALLED" << std::endl;
	*this = fragTrap;
}

FragTrap::~FragTrap()
{
	std::cout << "FRAGTRAP DESTRUCTOR CALLED" << std::endl;
	ClapTrap::~ClapTrap();
}

void	FragTrap::highFivesGuys()
{
	std::cout << "HIGH FIVES GUYS!" << std::endl;
}
