/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 23:44:08 by acaravan          #+#    #+#             */
/*   Updated: 2022/03/17 23:36:34 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

# include <iostream>
# include <string.h>
# include <iomanip>
# include <chrono>
# include <thread>

class	phonebook
{
	private:
		contact	arr[8];
		int		_oldestindex;
		int		_numberofContacts;
		int		_exit;
	public:
		void	add();
		int		search();
		void	exitcmd();
		int		&get_exit();

		phonebook();
};

#endif