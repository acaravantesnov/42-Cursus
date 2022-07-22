/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:32:45 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/22 13:57:46 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	*invalidbureaucrat = new Bureaucrat("JONNY", 250);
		(void)invalidbureaucrat;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat	*bureaucrat = new Bureaucrat("PEPE", 150);
	std::cout << *bureaucrat;

	try {bureaucrat->decrementGrade();}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << *bureaucrat;
	for (int i = 0; i < 149; i++)
		bureaucrat->incrementGrade();
	std::cout << *bureaucrat;

	try {bureaucrat->incrementGrade();}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << *bureaucrat;

	delete (bureaucrat);
	return (0);
}
