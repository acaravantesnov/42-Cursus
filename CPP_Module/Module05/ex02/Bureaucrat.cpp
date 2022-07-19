/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:32:40 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/20 01:38:37 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw (GradeTooHighException());
	else if (_grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat &bureaucrat) : _name(bureaucrat._name)
{
	this->_grade = bureaucrat._grade;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	Bureaucrat *b = new Bureaucrat(bureaucrat.getName(), bureaucrat.getGrade());
	return (*b);
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
	if (_grade - 1 < 1)
		throw	(GradeTooHighException());
	else
		_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw	(GradeTooLowException());
	else
		_grade++;
}

void	Bureaucrat::signForm(Form &form) const
{
	if (!(form.beSigned(*this)))
		throw (GradeTooLowException());
	else
		std::cout << this->getName() << " signs " << form.getName() << \
		std::endl;
}

void	Bureaucrat::executeForm(Form const & form)
{
	bool	b = true;

	try {form.execute(*this);}
	catch (std::exception e)
	{
		std::cout << "Bureaucrat " << this->getName() << " with grade " << \
		this->getGrade() << " was not able to execute form " << form.getName() \
		<< std::endl;
		b = false;
	}
	if (b)
		std::cout << this->getName() << " executes " << form.getName() << std::endl;
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
