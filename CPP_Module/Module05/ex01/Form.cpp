/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:33:13 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 19:11:14 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _grade2besigned(1), _grade2beexecuted(1)
{
	this->_is_it_signed = false;
}

Form::Form(const std::string name, const int grade2besigned, \
const int grade2beexecuted) : \
_name(name), _grade2besigned(grade2besigned), _grade2beexecuted(grade2beexecuted)															
{
	this->_is_it_signed = false;
}

Form::Form(const Form &form) :	_name(form.getName()), \
								_grade2besigned(form.getGrade2besigned()), \
								_grade2beexecuted(form.getGrade2beexecuted())
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

const int	Form::getGrade2besigned() const
{
	return (_grade2besigned);
}

const int	Form::getGrade2beexecuted() const
{
	return (_grade2beexecuted);
}

bool	Form::getIsItSigned() const
{
	return (_is_it_signed);
}

bool	Form::beSigned(const Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() <= this->_grade2besigned)
		{
			this->_is_it_signed = true;
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
	stream << form.getName() << ", form grade " << form.getGrade2besigned() << \
	"is ";
	if (!(form.getIsItSigned()))
		stream << "not ";
	stream << "signed" << std::endl;
	return (stream);
}
