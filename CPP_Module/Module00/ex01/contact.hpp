/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 23:31:49 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/07 21:18:52 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <chrono>
# include <thread>

class	contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phone;
		std::string	_darkestSecret;
	public:
		std::string &get_firstName();
		std::string &get_lastName();
		std::string &get_nickName();
		std::string &get_phone();
		std::string	&get_darkestSecret();

		void		set_firstName(std::string &firstName);
		void		set_lastName(std::string &lastName);
		void		set_nickName(std::string &nickName);
		void		set_phone(std::string &phone);
		void		set_darkestSecret(std::string &darkestSecret);

		contact();
		contact(std::string firstName, std::string lastName, \
		std::string nickName, std::string phone, std::string darkestSecret);
};

#endif
