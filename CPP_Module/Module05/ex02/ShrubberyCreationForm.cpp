/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:51:59 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/20 01:11:00 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :\
Form(target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm \
&scf)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	fileWrite;
	std::string		ascii_tree;

	if (this->getIsItSigned())
	{
		if (executor.getGrade() <= this->getGrade2beexecuted())
		{
			fileWrite.open(this->getName() + "_shrubbery", std::ios::out);
			ascii_tree = \
			"       _-_\n"
			"    /~~   ~~\\\n"
			" /~~         ~~\\\n"
			"{               }\n"
			" \\  _-     -_  /\n"
			"   ~  \\\\ //  ~\n"
			"_- -   | | _- _\n"
			"  _ -  | |   -_\n"
			"      // \\\\\n"
			"-----------------\n";
			fileWrite << ascii_tree << ascii_tree;
			fileWrite.close();
		}
		else
			throw (Bureaucrat::GradeTooLowException());
	}
	else
		throw (std::exception());
}
