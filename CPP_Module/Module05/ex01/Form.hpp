/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:33:10 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 19:08:36 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class	Bureaucrat;

class	Form
{
	private:
		const std::string	_name;
		const int			_grade2besigned;
		const int			_grade2beexecuted;
		bool				_is_it_signed;
	public:
		Form();
		Form(const std::string name, const int grade2besigned, \
		const int grade2beexecuted);
		Form(const Form &form);
		~Form();
		void				operator=(const Form &form);
	
		const std::string	getName() const;
		const int			getGrade2besigned() const;
		const int			getGrade2beexecuted() const;
		bool				getIsItSigned() const;

		bool				beSigned(const Bureaucrat &bureaucrat);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, Form const &form);

#endif