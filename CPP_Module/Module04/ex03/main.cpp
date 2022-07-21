/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:50:53 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/21 14:11:44 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	Ice			i;
	Cure 		c;
	Character	ch("PEPE");
	Character	ch2("JUAN");
	i.use(ch);
	c.use(ch);

	ch.equip(&i);
	ch.use(0, ch2);

	return (0);
}
