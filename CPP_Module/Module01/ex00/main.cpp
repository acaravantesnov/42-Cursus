/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 02:10:46 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/26 11:04:06 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	Uno = Zombie("Roberto");
	Uno.announce();
	Uno.randomChump("Pepe");

	Zombie *Dos = newZombie("Memo");
	Dos->announce();
}