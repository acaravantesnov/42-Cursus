/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:01:46 by acaravan          #+#    #+#             */
/*   Updated: 2022/04/10 19:30:50 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	ClapTrap();
	std::cout << "DEFAULT FRAGTRAP CONSTRUCTOR CALLED" << std::endl;
}

FragTrap::FragTrap(const std::string &Name) : ClapTrap(Name)
{
	std::cout << "FRAGTRAP CONSTRUCTOR CALLED" << std::endl;
	setHitpoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
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
