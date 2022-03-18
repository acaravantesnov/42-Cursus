/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 02:10:46 by acaravan          #+#    #+#             */
/*   Updated: 2022/03/18 21:21:33 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	/* Constructor with parameter creates a Zombie in the Stack.
	It is destroyed at the end of the main program. */

	Zombie	Uno("Roberto");
	Uno.announce();

	/* randomChump creates a Zombie (calls its constructor)
	and it announces itself.
	It is destroyed as soon as the function has ended executing. It has no return value. */

	Uno.randomChump("Pepe");

	/* newZombie creates a Zombie in the Heap.
	It is destroyed when called delete. */

	Zombie *Dos = newZombie("Memo");
	Dos->announce();
	delete(Dos);
}
