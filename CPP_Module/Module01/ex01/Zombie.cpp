/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 02:10:44 by acaravan          #+#    #+#             */
/*   Updated: 2022/03/18 21:23:51 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " has been destroyed. " << std::endl;
}

void	Zombie::announce()
{
	std::cout << '<' << _name << "> " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
