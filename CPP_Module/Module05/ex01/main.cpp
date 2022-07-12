/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:32:45 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 16:40:00 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	*bureaucrat = new Bureaucrat("PEPE", 120);
	Form		*form = new Form("JONNY", 100);
	form->beSigned(*bureaucrat);
	Form		*form2 = new Form("JOHN", 150);
	form2->beSigned(*bureaucrat);
	bureaucrat->signForm(*form2);
	return (0);
}