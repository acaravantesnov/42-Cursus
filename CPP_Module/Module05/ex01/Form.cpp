/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:33:13 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/20 19:45:18 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _grade2besigned(1), _grade2beexecuted(1)
{
	this->_is_it_signed = false;
}

Form::Form(const std::string name, const int grade2besigned, \
const int grade2beexecuted) : \
_name(name), _grade2besigned(grade2besigned),
_grade2beexecuted(grade2beexecuted), _is_it_signed(false)
{
	if ((_grade2besigned < 1) || (_grade2beexecuted < 1))
		throw (Form::GradeTooHighException());
	else if ((_grade2besigned > 150) || (_grade2beexecuted > 150))
		throw (Form::GradeTooLowException());
}

Form::Form(const Form &form) :	_name(form.getName()), \
								_grade2besigned(form.getGrade2besigned()), \
								_grade2beexecuted(form.getGrade2beexecuted()), \
								_is_it_signed(form.getIsItSigned())
{
	if ((_grade2besigned < 1) || (_grade2beexecuted < 1))
		throw (Form::GradeTooHighException());
	else if ((_grade2besigned > 150) || (_grade2beexecuted > 150))
		throw (Form::GradeTooLowException());
}

Form::~Form()
{

}

Form	&Form::operator=(const Form &form)
{
	if (this != &form)
		this->_is_it_signed = form.getIsItSigned();
	return (*this);
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

void	Form::setIsItSigned(const bool &is_it_signed)
{
	this->_is_it_signed = is_it_signed;
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
	return (0);
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
	" is ";
	if (!(form.getIsItSigned()))
		stream << "not ";
	stream << "signed" << std::endl;
	return (stream);
}
