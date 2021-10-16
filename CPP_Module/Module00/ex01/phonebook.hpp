/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 06:16:08 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/15 00:27:28 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string.h>

class PhoneBook
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string darkestSecret;
	public:
		PhoneBook(std::string,std::string,std::string,std::string,std::string);
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	printContact(int);
		void	printIndex();
};

PhoneBook::PhoneBook(std::string fN, std::string lN, std::string nN, std::string pN,
std::string dS)
{
	fN = firstName;
	lN = lastName;
	nN = nickName;
	pN = phoneNumber;
	dS = darkestSecret;
}

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}

void	PhoneBook::addContact()
{
	std::cout << "First Name: ";
	std::cin >> firstName;
	std::cout << "Last Name: ";
	std::cin >> lastName;
	std::cout << "Nickname: ";
	std::cin >> nickName;
	std::cout << "Phone Number: ";
	std::cin >> phoneNumber;
	std::cout << "Darkest Secret: ";
	std::cin >> darkestSecret;
}

void	PhoneBook::printContact(int nContact)
{
	std::cout << "|         " << nContact + 1 << '|';
	for(int i = 0; i < 3; i++)
	{
		switch (i)
		{
			case 0:
				if (firstName.length() <= 10)
				{
					for (unsigned long spc = 0; spc < (10 - firstName.length()); spc++)
						std::cout << ' ';
					std::cout << firstName;
				}
				else
				{
					for (unsigned long c = 0; c < 9; c++)
						std::cout << firstName[c];
					std::cout << '.';
				}
				break;
			case 1:
				if (lastName.length() <= 10)
				{
					for (unsigned long spc = 0; spc < (10 - lastName.length()); spc++)
						std::cout << ' ';
					std::cout << lastName;
				}
				else
				{
					for (unsigned long c = 0; c < 9; c++)
						std::cout << lastName[c];
					std::cout << '.';
				}
				break;
			case 2:
				if (nickName.length() <= 10)
				{
					for (unsigned long spc = 0; spc < (10 - nickName.length()); spc++)
						std::cout << ' ';
					std::cout << nickName;
				}
				else
				{
					for (unsigned long c = 0; c < 9; c++)
						std::cout << nickName[c];
					std::cout << '.';
				}
				break;
		}
		std::cout << '|';
	}
	std::cout << std::endl;
}

void	PhoneBook::printIndex()
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

#endif