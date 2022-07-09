/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:05:23 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 00:09:02 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class	RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(RobotomyRequestForm &robotomyRequestForm);
		~RobotomyRequestForm();
		void	operator=(const RobotomyRequestForm &robotomyRequestForm);

		virtual void		execute(Bureaucrat const &executor) const;
};

#endif
