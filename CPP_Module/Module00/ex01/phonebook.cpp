/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:14:37 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/15 00:23:08 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	std::string input = "";
	PhoneBook * u = new PhoneBook[8];
	for (int i = 0; i < 8; i++)
	{
		PhoneBook u = PhoneBook("","","","","");
	}

	int index;
	int nContacto;

	index = 0;
	nContacto = 0;
	while (nContacto <= 8)
	{
		std::cout << "\n* Introduce a valid command [ADD, SEARCH or EXIT] *\n\n\t\t     ";
		std::cin >> input;
		std::cout << std::endl;
		if (input.compare("ADD") == 0)
		{
			if (nContacto < 8 && nContacto >= 0)
			{
				u[nContacto].addContact();
				nContacto++;
			}
			else
			{
				std::cout << "ERROR: MAX NUMBER OF CONTACTS" << std::endl <<
				"Last Contact will be overwritten...\n\n" << std::endl;
				u[nContacto].~PhoneBook();
				nContacto--;
				u[nContacto].addContact();
				nContacto++;
			}
		}
		else if (input.compare("SEARCH") == 0)
		{
			int i = 0;
			std::cout << "/-------------------------------------------\\";
			std::cout << "\n|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" <<
			std::endl;
			std::cout << "|----------|----------|----------|----------|" <<
			std::endl;
			while (i < nContacto)
			{
				u[i].printContact(i);
				i++;
			}
			i = 0;
			std::cout << "\\-------------------------------------------/\n";
			std::cout << "\n-->	INDEX: "; std::cin >> index; std::cout << '\n';
			while ((index >= 1) && (index <= nContacto))
			{
				u[index - 1].printIndex();
				i++;
				index = 0;
			}
		}
		else if (input.compare("EXIT") == 0)
			return (0);
		input.empty();
	}
	return (0);
}
