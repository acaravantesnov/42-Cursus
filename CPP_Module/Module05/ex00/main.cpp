/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:32:45 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/11 00:53:45 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	*invalidbureaucrat = new Bureaucrat("JONNY", 250);
	Bureaucrat	*bureaucrat = new Bureaucrat("PEPE", 150);
	std::cout << *invalidbureaucrat;
	std::cout << *bureaucrat;
	try {bureaucrat->decrementGrade();}
	catch(Bureaucrat::GradeTooLowException e)
	{
		std::cout << "Cannot decrement grade anymore..." << std::endl;
	}
	std::cout << *bureaucrat;
	for (int i = 0; i < 149; i++)
		bureaucrat->incrementGrade();
	std::cout << *bureaucrat;
	try {bureaucrat->incrementGrade();}
	catch (Bureaucrat::GradeTooHighException e)
	{
		std::cout << "Cannot increment grade anymore..." << std::endl;
	}
	std::cout << *bureaucrat;
	delete (invalidbureaucrat);
	delete (bureaucrat);
	return (0);
}