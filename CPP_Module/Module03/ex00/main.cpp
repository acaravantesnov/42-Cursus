/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 01:42:02 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 17:58:18 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	std::cout << "---- CLAPTRAP MAIN ----\n" << std::endl;

	ClapTrap	ClaptrapA("ClaptrapA");
	ClapTrap	ClaptrapB("ClaptrapB");

	ClapTrap	ClapTrapC(ClaptrapA);
	std::cout << ClapTrapC << std::endl;

	std::cout << std::endl;

	std::cout << ClaptrapA << "\n" << ClaptrapB << std::endl;

	ClaptrapA.attack("ClaptrapB");
	ClaptrapB.takeDamage(ClaptrapA.getAttackDamage());

	std::cout << std::endl;

	std::cout << ClaptrapA << "\n" << ClaptrapB << std::endl;

	ClaptrapB.beRepaired(5);

	std::cout << std::endl;

	std::cout << ClaptrapA << "\n" << ClaptrapB << std::endl;
	return (0);
}
