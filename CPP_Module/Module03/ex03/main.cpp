/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 01:42:02 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/21 15:32:04 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	std::cout << "\n---- DIAMONDTRAP MAIN ----\n" << std::endl;

	DiamondTrap	DiamondTrapA("DiamondTrapA");
	DiamondTrap	DiamondTrapB("DiamondTrapB");

	std::cout << std::endl;

	std::cout << DiamondTrapA << "\n" << DiamondTrapB << std::endl;

	DiamondTrapA.attack("DiamondTrapB");
	DiamondTrapB.takeDamage(DiamondTrapA.getAttackDamage());

	std::cout << std::endl;

	std::cout << DiamondTrapA << "\n" << DiamondTrapB << std::endl;

	DiamondTrapB.beRepaired(5);

	std::cout << std::endl;

	std::cout << DiamondTrapA << "\n" << DiamondTrapB << std::endl;

	DiamondTrapB.guardGate();
	DiamondTrapB.highFivesGuys();
	DiamondTrapB.whoAmI();

	std::cout << std::endl;

	return (0);
}
