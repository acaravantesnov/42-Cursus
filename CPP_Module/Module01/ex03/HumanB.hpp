/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:50:12 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 17:28:24 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	private:
		Weapon *_weaponB;
		std::string	_name;
	public:
		HumanB();
		HumanB(std::string const &name);

		std::string	getName() const;
		void		setName(const std::string &name);
		void		setWeapon(Weapon &weapon);

		void		attack();
};

#endif