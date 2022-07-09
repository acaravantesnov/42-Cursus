/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    PresidentialPardonForm.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:07:53 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 00:09:02 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class	PresidentialPardonForm : public Form
{
	private:
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(PresidentialPardonForm &presidentialPardonForm);
		~PresidentialPardonForm();
		void	operator=(const PresidentialPardonForm &presidentialPardonForm);

		virtual void		execute(Bureaucrat const &executor) const;
};

#endif
