/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:16:13 by acaravan          #+#    #+#             */
/*   Updated: 2022/04/10 01:48:52 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Esta función permite crear un array de Zombies con un nombre distinto para cada uno */

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
	Zombie	*z = new Zombie[N];
	// Zombie[N] crea array de Zombies usando Default Constructor.
	// Como devuelve el puntero del primero, los Zombies se destruyen.
	for (int i = 0; i < N; i++)
	{
		std::string	custom_name = name + "_" + std::to_string(i + 1);
		z[i] = Zombie(custom_name);
	}
	// En el bucle for se crean todos los zombies con el constructor parametrizado.
	// Se destruiraén cuando llamemos a delete[] en el main.
	return (z);
}
