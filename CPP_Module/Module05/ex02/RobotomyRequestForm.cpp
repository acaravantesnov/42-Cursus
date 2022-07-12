/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:05:25 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/13 00:15:43 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form()
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : \
Form(target, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsItSigned())
	{
		if (this->getGrade2beexecuted() >= executor.getGrade())
		{
			int	n = rand()%2;
			if (n)
				std::cout << this->getName() << \
				" has been robotomized successfully" << std::endl;
			else
				std::cout << "XXXXXX FAILURE XXXXXX" << std::endl;
		}
		else
			throw (Bureaucrat::GradeTooLowException());
	}
	else
		throw (std::exception());
}
