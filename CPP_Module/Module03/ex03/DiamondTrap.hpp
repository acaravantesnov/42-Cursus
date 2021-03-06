/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:03:31 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/20 15:32:38 by acaravan         ###   ########.fr       */
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
	public:
		DiamondTrap();
		DiamondTrap(const std::string &Name);
		DiamondTrap(const DiamondTrap &diamondtrap);
		~DiamondTrap();
		DiamondTrap	&operator=(const DiamondTrap &diamondTrap);

		void	attack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string			&getName();

		void	whoAmI();
};

std::ostream	&operator<<(std::ostream &stream, DiamondTrap &diiamondtrap);

#endif
