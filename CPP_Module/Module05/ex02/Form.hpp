/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:33:10 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 00:03:10 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class	Form
{
	private:
		const std::string	_name;
		const std::string	_target;
		const int			_grade_required;
		bool				_is_it_signed;
		
	public:
		Form();
		Form(const std::string name, const int grade_required);
		Form(const Form &form);
		~Form();
		void				operator=(const Form &form);
	
		const std::string	getName() const;
		const std::string	getTarget() const;
		const int			getGradeRequired() const;
		bool				getIsItSigned() const;

		bool				beSigned(Bureaucrat const &bureaucrat);
		virtual void		execute(Bureaucrat const &executor) const = 0;

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