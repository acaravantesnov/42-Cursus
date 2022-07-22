/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:32:45 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/22 14:00:25 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	*bureaucrat = new Bureaucrat("PEPE", 120);

	Form		*form1 = new Form("JONNY", 100, 80);
	try {form1->beSigned(*bureaucrat);}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	Form		*form2 = new Form("JOHN", 130, 100);
	bureaucrat->signForm(*form2);

	Form		*form3 = new Form("JIMMY", 130, 100);
	form3->beSigned(*bureaucrat);
	std::cout << *form3;

	delete (bureaucrat);
	delete (form1);
	delete (form2);
	delete (form3);

	return (0);
}
