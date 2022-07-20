/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:32:40 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/20 18:53:49 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{

}

Bureaucrat::Bureaucrat(const std::string &name, int grade) :	_name(name),
																_grade(grade)
{
	if (_grade < 1)
		throw (GradeTooHighException());
	else if (_grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat &bureaucrat) :	_name(bureaucrat.getName()),
													_grade(bureaucrat.getGrade())
{

}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (bureaucrat._grade > 150)
		throw (GradeTooLowException());
	else if (bureaucrat._grade < 1)
		throw (GradeTooHighException());
	if (this != &bureaucrat)
		this->_grade = bureaucrat._grade;
	return (*this);
}

const std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade > 1)
		_grade--;
	else
		throw	(GradeTooHighException());
}

void	Bureaucrat::decrementGrade()
{
	if (_grade < 150)
		_grade++;
	else
		throw	(GradeTooLowException());
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

std::ostream	&operator<<(std::ostream &stream, Bureaucrat const &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << \
	bureaucrat.getGrade() << std::endl;
	return (stream);
}
