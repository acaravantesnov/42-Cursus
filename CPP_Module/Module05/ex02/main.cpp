/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:53:12 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/13 00:22:31 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

# define BLUE "\e[0;34m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[1;33m"
# define RESET "\e[0m"

int	main(void)
{
	std::cout << RED << "*------------------Testing the ShrubberyCreationForm------------------*" << RESET << std::endl;
	Bureaucrat bureaucrat1("haha", 1);
	Bureaucrat bureaucrat2("braiiz", 10);
	ShrubberyCreationForm scf("Home");
	std::cout << "Name: " << scf.getName() << std::endl;
	std::cout << "GradeToExec: " << scf.getGrade2beexecuted() << std::endl;
	std::cout << "GradeToSign: " << scf.getGrade2besigned() << std::endl;
	std::cout << std::endl;

	try {
		scf.execute(bureaucrat1);
	} catch (std::exception &e) {
		std::cout << GREEN << e.what() << RESET << std::endl;
	}
	scf.beSigned(bureaucrat2);
	scf.execute(bureaucrat2);
	std::cout << std::endl;

	std::cout << RED << "*------------------Testing the RobotomyRequestForm------------------*" << RESET << std::endl;
	RobotomyRequestForm rrf("homeAgain");
	std::cout << "Name: " << rrf.getName() << std::endl;
	std::cout << "GradeToExec: " << rrf.getGrade2beexecuted() << std::endl;
	std::cout << "GradeToSign: " << rrf.getGrade2besigned() << std::endl;
	std::cout << std::endl;

	try {
		rrf.execute(bureaucrat1);
	} catch (std::exception &e) {
		std::cout << GREEN << e.what() << RESET << std::endl;
	}
	rrf.beSigned(bureaucrat2);
	rrf.execute(bureaucrat2);
	std::cout << std::endl;

	std::cout << RED << "*------------------Testing the PresidentialPardonForm------------------*" << RESET << std::endl;
	Bureaucrat bureaucrat3("haha", 4);
	PresidentialPardonForm ppf("homeAgain");
	std::cout << "Name: " << ppf.getName() << std::endl;
	std::cout << "GradeToExec: " << ppf.getGrade2beexecuted() << std::endl;
	std::cout << "GradeToSign: " << ppf.getGrade2besigned() << std::endl;
	std::cout << std::endl;

	try {
		ppf.execute(bureaucrat3);
	} catch (std::exception &e) {
		std::cout << GREEN << e.what() << RESET << std::endl;
	}
	ppf.beSigned(bureaucrat3);
	ppf.execute(bureaucrat3);
	return (0);
}
