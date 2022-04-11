/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:03:31 by acaravan          #+#    #+#             */
/*   Updated: 2022/04/11 13:00:47 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	_Name;
		DiamondTrap();
	public:
		DiamondTrap(const std::string &Name);
		void	attack(std::string const & target);
};

#endif