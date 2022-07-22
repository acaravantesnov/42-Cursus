/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:04:14 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/22 14:15:01 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(Intern const &intern)
{
	*this = intern;
}

Intern::~Intern()
{

}

Intern	&Intern::operator=(Intern const &intern)
{
	(void)intern;
	return (*this);
}

Form*	Intern::makeForm(const std::string &name, const std::string &target) const
{
	struct	s_createform createform[3] = \
	{
		{"shrubbery creation", new ShrubberyCreationForm(target)},
		{"robotomy request", new RobotomyRequestForm(target)},
		{"presidential pardon", new PresidentialPardonForm(target)}
	};

	Form	*formptr;
	for (int i = 0; i < 3; i++)
	{
		if (name == createform[i].form_name)
			formptr = createform[i].instanceptr;
	}
	return (formptr);
}
