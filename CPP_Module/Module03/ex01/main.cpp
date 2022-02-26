/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 01:42:02 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/26 04:43:12 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	std::cout << "\n---- CLAPTRAP MAIN ----\n" << std::endl;
	
	ClapTrap	ClaptrapA("ClaptrapA");
	ClapTrap	ClaptrapB(ClaptrapA);

	std::cout << std::endl;
	
	std::cout << ClaptrapA << "\n" << ClaptrapB << std::endl;

	ClaptrapA.attack("ClaptrapB");
	ClaptrapB.takeDamage(ClaptrapA.getAttackDamage());

	std::cout << std::endl;
	
	std::cout << ClaptrapA << "\n" << ClaptrapB << std::endl;
	
	ClaptrapB.beRepaired(5);
	
	std::cout << std::endl;
	
	std::cout << ClaptrapA << "\n" << ClaptrapB << std::endl;

	std::cout << "\n---- SCAVTRAP MAIN ----\n" << std::endl;

	ScavTrap	ScavTrapA("ScavTrapA");
	ScavTrap	ScavTrapB(ScavTrapA);

	std::cout << std::endl;
	
	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;

	ScavTrapA.attack("ScavTrapB");
	ScavTrapB.takeDamage(ScavTrapA.getAttackDamage());

	std::cout << std::endl;
	
	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;
	
	ScavTrapB.beRepaired(5);
	
	std::cout << std::endl;
	
	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;

	ScavTrapB.guardGate();

	std::cout << std::endl;
	
	return (0);
}
