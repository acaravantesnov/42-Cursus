/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:33:13 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/18 17:46:47 by acaravan         ###   ########.fr       */
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

Form	&Form::operator=(const Form &form)
{
	Form f(form.getName(), form.getGrade2besigned(), form.getGrade2beexecuted());
	return (f);
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
	if (bureaucrat.getGrade() <= this->_grade2besigned)
	{
		this->_is_it_signed = true;
		return (1);
	}
	else
		throw (GradeTooLowException());
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
