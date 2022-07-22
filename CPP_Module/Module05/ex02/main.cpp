/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:53:12 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/22 14:11:08 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	Bureaucrat				b1("Alberto", 1);
	ShrubberyCreationForm	scf1("Casa");
	RobotomyRequestForm		rrf1("Casa");
	PresidentialPardonForm	ppf1("Casa");

	b1.signForm(rrf1);
	b1.executeForm(rrf1);
	ppf1.beSigned(b1);
	try {ppf1.execute(b1);}
	catch (std::exception e)
	{
		std::cout << "Error" << std::endl;
	}
	return (0);
}
