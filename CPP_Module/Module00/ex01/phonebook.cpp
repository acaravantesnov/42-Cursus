/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 23:42:30 by acaravan          #+#    #+#             */
/*   Updated: 2022/01/10 20:31:55 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	header()
{
	std::cout << "*-------------------------------------------*" << std::endl;
	std::cout << "|                PHONEBOOK                  |" << std::endl;
	std::cout << "*-------------------------------------------*" << std::endl;
}

int	main(void)
{
	std::string	command;
	phonebook	book;

	header();
	while(book.get_exit() != 1)
	{
		std::cout << std::endl;
		std::cout << "    Command: "; std::cin >> command;
	
		if (command.compare("ADD") == 0)
			book.add();
		else if (command.compare("SEARCH") == 0)
		{
			if (book.search() == 1)
				std::cout << "\n    No contacts available yet " << std::endl;
		}
		else if (command.compare("EXIT") == 0)
			book.exitcmd();
		else
			std::cout << "    Error: Invalid Command\n";
	}
}