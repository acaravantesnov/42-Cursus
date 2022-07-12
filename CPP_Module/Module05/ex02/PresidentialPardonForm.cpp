/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:08:00 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/13 00:20:34 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form()
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : \
Form(target, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm \
&ppf)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsItSigned())
	{
		if (this->getGrade2beexecuted() >= executor.getGrade())
			std::cout << this->getName() << \
			" has been pardoned by Zafod Beeblebrox." << std::endl;
		else
			throw (Bureaucrat::GradeTooLowException());
	}
	else
		throw (std::exception());
}