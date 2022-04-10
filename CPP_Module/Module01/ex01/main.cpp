/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:15:23 by acaravan          #+#    #+#             */
/*   Updated: 2022/04/10 01:34:36 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main()
{
	int N = 10;
	Zombie	*z = zombieHorde(N, "Pepe");
	if (z == NULL)
		return (1);
	for (int i = 0; i < N; i++)
	{
		z[i].announce();
	}
	delete[] z;
	return (0);
}
