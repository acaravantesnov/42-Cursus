/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:32:45 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 21:32:03 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	*invalidbureaucrat = new Bureaucrat("JONNY", 250); //Should it delete instance?
	Bureaucrat	*bureaucrat = new Bureaucrat("PEPE", 150);
	std::cout << *bureaucrat;
	bureaucrat->decrementGrade();
	std::cout << *bureaucrat;
	for (int i = 0; i < 149; i++)
		bureaucrat->incrementGrade();
	std::cout << *bureaucrat;
	bureaucrat->incrementGrade();
	std::cout << *bureaucrat;
	delete (invalidbureaucrat);
	delete bureaucrat;
	return (0);
}