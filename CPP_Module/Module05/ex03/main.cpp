/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:53:12 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/20 20:39:22 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern	someRandomIntern;

	Form*	rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf;

	Bureaucrat*	b = new Bureaucrat("Alberto", 1);
	b->signForm(*rrf);
	rrf->execute(*b);

	delete (rrf);
	delete (b);

	return (0);
}
