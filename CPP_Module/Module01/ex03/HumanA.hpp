/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:50:17 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 17:28:33 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	private:
		Weapon &_weaponA;
		std::string	_name;
	public:
		HumanA(std::string const &name, Weapon &weapon);

		std::string	getName() const;
		void		setName(const std::string &name);

		void		attack();
};

#endif