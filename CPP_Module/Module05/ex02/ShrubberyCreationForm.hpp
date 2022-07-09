/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:51:57 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 00:07:33 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class	ShrubberyCreationForm : public Form
{
	private:
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(ShrubberyCreationForm &shrubberyCreationForm);
		~ShrubberyCreationForm();
		void	operator=(const ShrubberyCreationForm &shrubberyCreationForm);

		virtual void		execute(Bureaucrat const &executor) const;
};

#endif