/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 23:42:30 by acaravan          #+#    #+#             */
/*   Updated: 2022/03/18 20:46:41 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int		&phonebook::get_exit()
{
	return (_exit);
}

void	phonebook::add()
{
	if (_numberofContacts < 8)
		_numberofContacts++;
	if (_oldestindex == 8)
		_oldestindex = 0;
	if (_numberofContacts > 8)
	{
		std::string string;
		std::cout << "\n*-------------------------------------------*" << std::endl;
		std::cout << "\n    First Name: "; getline(std::cin, string); this->arr[_oldestindex].set_firstName(string);
		std::cout << "    Last Name: "; getline(std::cin, string); this->arr[_oldestindex].set_lastName(string);
		std::cout << "    Nickname: "; getline(std::cin, string); this->arr[_oldestindex].set_nickName(string);
		std::cout << "    Phone Number: ";getline(std::cin, string); this->arr[_oldestindex].set_phone(string);
		std::cout << "    Darkest Secret: "; getline(std::cin, string); this->arr[_oldestindex].set_darkestSecret(string);
		std::cout << "\n*-------------------------------------------*" << std::endl;
		_oldestindex++;
	}
	else
	{
		std::string string;
		std::cout << "\n*-------------------------------------------*" << std::endl;
		std::cout << "\n    First Name: "; getline(std::cin, string); this->arr[_numberofContacts - 1].set_firstName(string);
		std::cout << "    Last Name: "; getline(std::cin, string); this->arr[_numberofContacts - 1].set_lastName(string);
		std::cout << "    Nickname: "; getline(std::cin, string); this->arr[_numberofContacts - 1].set_nickName(string);
		std::cout << "    Phone Number: "; getline(std::cin, string); this->arr[_numberofContacts - 1].set_phone(string);
		std::cout << "    Darkest Secret: "; getline(std::cin, string); this->arr[_numberofContacts - 1].set_darkestSecret(string);
		std::cout << "\n*-------------------------------------------*" << std::endl;
	}
}

int		phonebook::search()
{
	std::string	string;
	int			index;
	if (_numberofContacts > 0)
	{
		std::cout << "\n*-------------------------------------------*" << std::endl;
		std::cout << "|     INDEX| FIRSTNAME|  LASTNAME|  NICKNAME|" << std::endl;
		std::cout << "*-------------------------------------------*" << std::endl;
		for(int i = 0; (i < _numberofContacts) && (i < 8); i++)
		{
			std::cout << "|"; std::cout << std::setw(10) << std::right << i + 1;

			if (this->arr[i].get_firstName().length() > 9)
			{
				string = this->arr[i].get_firstName().substr(0, 9);
				std::cout << "|"; std::cout << std::setw(10) << std::right << string.append(".");
			}
			else
			{
				std::cout << "|"; std::cout << std::setw(10) << std::right << this->arr[i].get_firstName();
			}

			if (this->arr[i].get_lastName().length() > 9)
			{
				string = this->arr[i].get_lastName().substr(0, 9);
				std::cout << "|"; std::cout << std::setw(10) << std::right << string.append(".");
			}
			else
			{
				std::cout << "|"; std::cout << std::setw(10) << std::right << this->arr[i].get_lastName();
			}

			if (this->arr[i].get_nickName().length() > 9)
			{
				string = this->arr[i].get_nickName().substr(0, 9);
				std::cout << "|"; std::cout << std::setw(10) << std::right << string.append(".");
			}
			else
			{
				std::cout << "|"; std::cout << std::setw(10) <<  std::right << this->arr[i].get_nickName();
			}
			std::cout << "|"; std::setw(1); std::cout << "\n";

		}
		std::cout << "*-------------------------------------------*\n" << std::endl;
		std::cout << "Select a valid index: "; std::cin >> index;
		while ((!std::cin.good()) || (index < 1) || (index > _numberofContacts))
		{
			std::cout << "ERROR: Introduce valid numeric value\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "\nSelect a valid index: "; std::cin >> index;
			std::cin.clear();
		}
		std::cout << "\n*	     INFO ABOUT CONTACT " << index << "           *\n" << std::endl;
		std::cout << "  First Name: " << this->arr[index - 1].get_firstName() << std::endl;
		std::cout << "  Last Name: " << this->arr[index - 1].get_lastName() << std::endl;
		std::cout << "  Nickname: " << this->arr[index - 1].get_nickName() << std::endl;
		std::cout << "  Phone Number: " << this->arr[index - 1].get_phone() << std::endl;
		std::cout << "  Darkest Secret: " << this->arr[index - 1].get_darkestSecret() << std::endl;

	}
	else
		return (1);
	return (0);
}

void	phonebook::exitcmd()
{
	_exit = 1;

	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|               SEE YOU SOON!               |" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "*-------------------------------------------*" << std::endl;
}

phonebook::phonebook()
{
	_numberofContacts = 0;
	_oldestindex = 0;
	_exit = 0;
}