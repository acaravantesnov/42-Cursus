/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:50:07 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/29 15:54:53 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class	Weapon
{
	private:
		std::string	_type;
	public:
		Weapon();
		explicit Weapon(const std::string &type);
		std::string	const &getType() const;
		void		setType(const std::string &type);
};

#endif
