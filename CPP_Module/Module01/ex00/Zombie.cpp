/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 02:10:44 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/26 09:57:31 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	_name = name;
}

void	Zombie::announce()
{
	std::cout << '<' << _name << "> " << "BraiiiiiiinnnzzzZ..." << std::endl;
}