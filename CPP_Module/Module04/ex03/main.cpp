/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:50:53 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/21 14:32:24 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

void	leaks()
{
	system("leaks Interface");
}

int main()
{
	atexit(leaks);
	Ice			i;
	Cure 		c;

	MateriaSource	ms;
	ms.learnMateria(&i);
	ms.learnMateria(&c);

	Character	ch1("Alberto");
	Character	ch2("Juan");
	ch1.equip(ms.createMateria("cure"));
	ch1.use(0, ch2);

	return (0);
}
