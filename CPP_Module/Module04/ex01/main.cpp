/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:50:53 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/25 13:04:41 by acaravan         ###   ########.fr       */
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
	return (0);
}

/*
//SUBJECT MAIN FUNCTION
int main()
{
	atexit(leaks);
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;
}
*/
/*
//DEEP COPY MAIN
int	main()
{
	Dog basic;
	basic.getBrainptr()->getideas()[0] = "Hi";
	Dog tmp = basic;
	std::cout << tmp.getBrainptr()->getideas()[0] << std::endl;
	basic.getBrainptr()->getideas()[0] = "Bye";
	std::cout << basic.getBrainptr()->getideas()[0] << std::endl;
	std::cout << tmp.getBrainptr()->getideas()[0] << std::endl;
	return (0);
}
*/
