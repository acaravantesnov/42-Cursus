/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:04:11 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/22 14:13:13 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern(Intern const &intern);
		virtual ~Intern();
		Intern	&operator=(Intern const &intern);

		Form*	makeForm(const std::string &name, const std::string &target) const;
};

struct	s_createform
{
	std::string	form_name;
	Form		*instanceptr;
};

#endif
