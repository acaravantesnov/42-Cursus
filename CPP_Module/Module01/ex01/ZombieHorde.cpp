/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:16:13 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 23:37:57 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
	Zombie	*z = new Zombie[N];
	// Zombie[N] creates a Zombie array using default constructor.
	for (int i = 0; i < N; i++)
	{
		std::string	custom_name = name + "_" + std::to_string(i + 1);
		z[i].setName(custom_name);
	}
	// Zombies will get destroyed when we call delete[] in main.
	return (z);
}
