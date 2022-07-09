/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:32:45 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 23:44:20 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	*bureaucrat = new Bureaucrat("PEPE", 150);
	Form		*form = new Form("JONNY", 100);
	form->beSigned(*bureaucrat);
	return (0);
}