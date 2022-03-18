/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 23:29:53 by acaravan          #+#    #+#             */
/*   Updated: 2022/03/18 20:45:43 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

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

	while(book.get_exit() != 1)
	{
		header();
		std::cout << std::endl;
		std::cout << "    Command: "; std::cin >> command;
		std::cin.ignore();
		if (command.compare("ADD") == 0)
		{
			book.add();
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			system("clear");
		}
		else if (command.compare("SEARCH") == 0)
		{
			if (book.search() == 1)
				std::cout << "\n    No contacts available yet " << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			system("clear");
		}
		else if (command.compare("EXIT") == 0)
			book.exitcmd();
		else
		{
			std::cout << "    Error: Invalid Command\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			system("clear");
		}
	}
}
