/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:50:53 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/18 17:01:00 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define N 10

void	leaks()
{
	system("leaks I_dont_want_to_set_the_world_on_fire");
}

int main()
{
	atexit(leaks);
	
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
	
	// DEEP COPY
	
	std::cout << std::endl;
	Dog	*dog1 = new Dog;
	Dog *dog2 = new Dog;

	*dog2 = *dog1;
	std::cout << dog2->getType() << std::endl;
	dog1->setType("MUTANT DOG");
	std::cout << dog1->getType() << std::endl;
	std::cout << dog2->getType() << std::endl;

	std::cout << std::endl;

	delete (dog1);
	delete (dog2);

	std::cout << std::endl;

	return (0);
}

/*
//Subject main fct

int main()
{
	atexit(leaks);
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;
}
*/