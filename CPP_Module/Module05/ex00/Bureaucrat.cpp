/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:32:40 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 22:18:03 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) :	_name(name),
																_grade(grade)
{
	try
	{
		if (_grade < 1)
			throw (GradeTooHighException());
		else if (_grade > 150)
			throw (GradeTooLowException());
	}
	catch (GradeTooHighException e)
	{
		std::cout << "Invalid grade..." << std::endl;
	}
	catch (GradeTooLowException e)
	{
		std::cout << "Invalid grade..." << std::endl;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat &bureaucrat) : _name(bureaucrat._name)
{
	this->_grade = bureaucrat._grade;
}

Bureaucrat::~Bureaucrat()
{

}

void	Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	// ?
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
	try
	{
		_grade--;
		if (_grade < 1)
			throw	(GradeTooHighException());
	}
	catch (GradeTooHighException e)
	{
		std::cout << "Cannot increment grade anymore..." << std::endl;
		_grade++;
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		_grade++;
		if (_grade > 150)
			throw	(GradeTooLowException());
	}
	catch (GradeTooLowException e)
	{
		std::cout << "Cannot decrement grade anymore..." << std::endl;
		_grade--;
	}
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