/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:08:57 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/18 17:09:28 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain &brain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this  = brain;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain	&Brain::operator=(Brain const &brain)
{
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			(this->ideas)[i] = (brain.ideas)[i];
	}
	return (*this);
}