/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:05:25 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/20 19:49:26 by acaravan         ###   ########.fr       */
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

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf) : \
Form(rrf)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const \
&rrf)
{
	if (this != &rrf)
		this->setIsItSigned(rrf.getIsItSigned());
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	int	n;

	srand(time(NULL));
	if (this->getIsItSigned())
	{
		if (this->getGrade2beexecuted() >= executor.getGrade())
		{
			n = rand()%2;
			if (n)
				std::cout << this->getName() << \
				" has been robotomized successfully" << std::endl;
			else
				std::cout << "Brrrrrrrrrrrrrrrrrrrrrrrr" << std::endl;
		}
		else
			throw (Bureaucrat::GradeTooLowException());
	}
	else
		throw (std::exception());
}
