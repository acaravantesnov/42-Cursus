/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 01:42:02 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 18:29:50 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	std::cout << "\n---- FRAGTRAP MAIN ----\n" << std::endl;

	FragTrap	FragTrapA("FragTrapA");
	FragTrap	FragTrapB("FragTrapB");

	std::cout << std::endl;

	std::cout << FragTrapA << "\n" << FragTrapB << std::endl;

	FragTrapA.attack("FragTrapB");
	FragTrapB.takeDamage(FragTrapA.getAttackDamage());

	std::cout << std::endl;

	std::cout << FragTrapA << "\n" << FragTrapB << std::endl;

	FragTrapB.beRepaired(5);

	std::cout << std::endl;

	std::cout << FragTrapA << "\n" << FragTrapB << std::endl;

	FragTrapB.highFivesGuys();

	std::cout << std::endl;

	return (0);
}
