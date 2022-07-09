/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 02:10:46 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 17:36:50 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	/* Constructor with parameter creates a Zombie in the Stack.
	It is destroyed at the end of the main program. */

	Zombie	One("Roberto");
	One.announce();

	/* randomChump creates a Zombie (calls its constructor)
	and it announces itself.
	It is destroyed as soon as the function has ended executing.
	It has no return value. */

	One.randomChump("Pepe");

	/* newZombie creates a Zombie in the Heap.
	It is destroyed when called delete. */

	Zombie *Two = newZombie("Memo");
	Two->announce();
	delete(Two);
}
