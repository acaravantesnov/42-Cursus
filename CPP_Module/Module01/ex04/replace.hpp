/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 03:36:14 by acaravan          #+#    #+#             */
/*   Updated: 2021/10/08 00:18:41 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>

class Replace
{
private:
	std::string	_fileName;
	std::string	_s1;
	std::string	_s2;
public:
	Replace(const std::string &fileName, const std::string &s1, const std::string &s2);
	~Replace();
	void replace();
};

#endif