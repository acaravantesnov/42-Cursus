/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:50:53 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 01:43:54 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define N 10

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
	
	for (int i = 0; i < N; i++)
		delete (animals[i]);
	return (0);
}
