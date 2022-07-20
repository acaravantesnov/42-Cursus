/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Real_type.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:12:30 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/20 21:25:07 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Real_type.hpp"

Base::~Base() {}

Base	*generate(void)
{
	int		opt;
	Base	*instance;

	srand(time(NULL));
	opt = (rand()%3) + 1;
	std::cout << opt << std::endl;
	switch (opt)
	{
		case (1):
			instance = new A;
			break;
		case (2):
			instance = new B;
			break;
		case (3):
			instance = new C;
			break;
	}
	return (instance);
}

void	identify(Base *p)
{
	A	*a = dynamic_cast<A*>(p);
	B	*b = dynamic_cast<B*>(p);
	C	*c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "A" << std::endl;
	else if (b)
		std::cout << "B" << std::endl;
	else if (c)
		std::cout << "C" << std::endl;
}
