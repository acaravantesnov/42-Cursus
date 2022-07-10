/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 02:10:44 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 23:35:17 by acaravan         ###   ########.fr       */
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

void	Zombie::announce(void)
{
	std::cout << '<' << _name << "> " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
