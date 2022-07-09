/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:33:13 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 00:45:17 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _grade_required(150)
{
	this->_is_it_signed = 0;
}

Form::Form(const std::string name, const int grade_required) : \
_name(name), _grade_required(grade_required)															
{
	this->_is_it_signed = 0;
}

Form::Form(const Form &form) :	_name(form.getName()),
								_grade_required(form.getGradeRequired())
{
	this->_is_it_signed = form.getIsItSigned();
}

Form::~Form()
{
	
}

void	Form::operator=(const Form &form)
{
	// ?
}

const std::string	Form::getName() const
{
	return (_name);
}

const int	Form::getGradeRequired() const
{
	return (_grade_required);
}

bool	Form::getIsItSigned() const
{
	return (_is_it_signed);
}

bool	Form::beSigned(const Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() <= this->_grade_required)
		{
			this->_is_it_signed = 1;
			return (1);
		}
		else
			throw (GradeTooLowException());
	}
	catch (GradeTooLowException e)
	{
		std::cout << "Form cannot be signed, grade is too low." << std::endl;
		return (0);
	}
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

std::ostream	&operator<<(std::ostream &stream, Form const &form)
{
	stream << form.getName() << ", form grade " << form.getGradeRequired() << \
	"is ";
	if (!(form.getIsItSigned()))
		stream << "not ";
	stream << "signed" << std::endl;
	return (stream);
}
