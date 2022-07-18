/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:50:53 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/18 16:15:20 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define N 10

/*
int main()
{
	Animal *animals[N];
	for (int i = 0; i < N; i++)
	{
		if (i < N / 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	std::cout << std::endl;
	for (int i = 0; i < N; i++)
		delete (animals[i]);
	return (0);
}
*/

void	leaks()
{
	system("leaks I_don’t_want_to_set_the_world_on_fire");
}

int main()
{
	atexit(leaks);
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;
}

