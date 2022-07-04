/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:16:13 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/03 19:24:01 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Esta función permite crear un array de Zombies con un nombre distinto para cada uno */

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
	Zombie	*z = new Zombie[N];
	// Zombie[N] creates a Zombie array using default constructor.
	// As it returns a pointer to the first element, all instances get destroyed.
	for (int i = 0; i < N; i++)
	{
		std::string	custom_name = name + "_" + std::to_string(i + 1);
		z[i] = Zombie(custom_name);
	}
	// In for loop all zombies will be created with the parametrized constructor.
	// They will get destroyed when we call delete[] in main.
	return (z);
}
