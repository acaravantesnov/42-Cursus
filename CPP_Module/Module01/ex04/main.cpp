/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:10:52 by acaravan          #+#    #+#             */
/*   Updated: 2022/04/10 03:30:23 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	main(int argc, char *argv[])
{
	std::string name;
	std::string s1;
	std::string s2;

	if ((argc != 4) || (!argv[2]) || (!argv[3]))
		return (0);
	name = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	Replace file(name, s1, s2);
	file.replace();
	return (0);
}