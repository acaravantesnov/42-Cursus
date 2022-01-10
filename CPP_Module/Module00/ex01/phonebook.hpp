/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 23:44:08 by acaravan          #+#    #+#             */
/*   Updated: 2022/01/10 20:48:33 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
// PRAGMA ONCE

# include <iostream>
# include <string.h>

class	contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phone;
		std::string	_darkestSecret;
	public:
		std::string get_firstName();
		std::string get_lastName();
		std::string get_nickName();
		std::string get_phone();
		std::string	get_darkestSecret();

		void		set_firstName(std::string &firstName);
		void		set_lastName(std::string &lastName);
		void		set_nickName(std::string &nickName);
		void		set_phone(std::string &phone);
		void		set_darkestSecret(std::string &darkestSecret);

		contact() {}
		contact(std::string firstName, std::string lastName, std::string nickName,
		std::string phone, std::string darkestSecret)
		{
			_firstName = firstName;
			_lastName = lastName;
			_nickName = nickName;
			_phone = phone;
			_darkestSecret = darkestSecret;
		}
};

class	phonebook
{
	private:
		contact	arr[8];
		int		_numberofContacts;
		int		_exit;
	public:
		void	add();
		int		search();
		void	exitcmd();
		int		&get_exit() {return (_exit);}
		
		phonebook()
		{
			_numberofContacts = 0;
			_exit = 0;
		}
};

std::string contact::get_firstName()
{
	std::string	string;
	for (int i = 0; i < (10 - _firstName.length()); i++)
		string += ' ';
	string += _firstName;
	return (string);
}
std::string contact::get_lastName()
{
	std::string	string;
	for (int i = 0; i < (10 - _lastName.length()); i++)
		string += ' ';
	string += _lastName;
	return (string);
}
std::string contact::get_nickName()
{
	std::string	string;
	for (int i = 0; i < (10 - _nickName.length()); i++)
		string += ' ';
	string += _nickName;
	return (string);
}
std::string contact::get_phone()
{
	return (_phone);
}
std::string	contact::get_darkestSecret()
{
	return (_darkestSecret);
}

void		contact::set_firstName(std::string &firstName) {_firstName = firstName;}
void		contact::set_lastName(std::string &lastName) {_lastName = lastName;}
void		contact::set_nickName(std::string &nickName) {_nickName = nickName;}
void		contact::set_phone(std::string &phone) {_phone = phone;}
void		contact::set_darkestSecret(std::string &darkestSecret) {_darkestSecret = darkestSecret;}

void	phonebook::add()
{
	_numberofContacts++;
	std::string string;
	std::cout << "\n*-------------------------------------------*" << std::endl;
	std::cout << "\n    First Name: "; std::cin >> string; this->arr[_numberofContacts - 1].set_firstName(string);
	std::cout << "    Last Name: "; std::cin >> string; this->arr[_numberofContacts - 1].set_lastName(string);
	std::cout << "    Nickname: "; std::cin >> string; this->arr[_numberofContacts - 1].set_nickName(string);
	std::cout << "    Phone Number: "; std::cin >> string; this->arr[_numberofContacts - 1].set_phone(string);
	std::cout << "    Darkest Secret: "; std::cin >> string; this->arr[_numberofContacts - 1].set_darkestSecret(string);
	std::cout << "\n*-------------------------------------------*" << std::endl;
}

int		phonebook::search()
{
	std::string	string;
	if (_numberofContacts > 0)
	{
		std::cout << "\n*-------------------------------------------*" << std::endl;
		std::cout << "|     INDEX| FIRSTNAME|  LASTNAME|  NICKNAME|" << std::endl;
		std::cout << "*-------------------------------------------*" << std::endl;
		for(int i = 0; i < _numberofContacts; i++)
		{
			std::cout << "|         " << i + 1 << '|';
			if (this->arr[i].get_firstName().length() <= 10)
				std::cout << this->arr[i].get_firstName() << '|';
			else
			{
				string = this->arr[i].get_firstName();
				string.resize(0,9);
				this->arr[i].set_firstName(string);
				std::cout << this->arr[i].get_firstName() << ".|";
			}
			if (this->arr[i].get_lastName().length() <= 10)
				std::cout << this->arr[i].get_lastName() << '|';
			else
			{
				string = this->arr[i].get_lastName();
				string.resize(0,9);
				this->arr[i].set_lastName(string);
				std::cout << this->arr[i].get_lastName() << ".|";
			}	
			if (this->arr[i].get_nickName().length() <= 10)
				std::cout << this->arr[i].get_nickName() << '|' << std::endl;
			else
			{
				string = this->arr[i].get_nickName();
				string.resize(0,9);
				this->arr[i].set_nickName(string);
				std::cout << this->arr[i].get_nickName() << ".|";
			}
		}
		std::cout << "*-------------------------------------------*" << std::endl;
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

#endif