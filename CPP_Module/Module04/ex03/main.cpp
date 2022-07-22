/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:50:53 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/22 13:55:43 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
	Ice			i;
	Cure 		c;

	MateriaSource	ms;
	ms.learnMateria(&i);
	ms.learnMateria(&c);

	Character	ch1("Alberto");
	Character	ch2("Juan");
	AMateria *ptr = ms.createMateria("cure");
	ch1.equip(ptr);
	ch1.equip(&i);
	ch1.unequip(0);
	ch1.use(0, ch2);

	//DEEP COPY
	std::cout << std::endl;
	Character	ch3(ch1);
	std::cout << "ch3 uses item 0 against ch1 -> "; ch3.use(0, ch1);
	ch1.equip(&c);
	std::cout << "ch1 uses item 1 against ch2 -> "; ch1.use(1, ch2);
	std::cout << "ch3 uses item 1 against ch2 -> "; ch3.use(1, ch2);

	delete (ptr);
	return (0);
}
