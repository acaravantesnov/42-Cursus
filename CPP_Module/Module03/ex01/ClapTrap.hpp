/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 01:32:20 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/26 04:21:01 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class	ClapTrap
{
	protected:
		std::string	_Name;
		int			_Hitpoints;
		int			_EnergyPoints;
		int			_AttackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string Name);
		ClapTrap(ClapTrap const &clapTrap);
		virtual ~ClapTrap();

		std::string			&getName();
		void				setName(std::string &Name);
		int					&getHitpoints();
		void				setHitpoints(int &Hitpoints);
		int					&getEnergyPoints();
		void				setEnergyPoints(int &EnergyPoints);
		int					&getAttackDamage();
		void				setAttackDamage(int &AttackDamage);

		ClapTrap			&operator=(ClapTrap const &clapTrap2);
		friend std::ostream	&operator<<(std::ostream &stream, ClapTrap const &clapTrap2);
		
		void				attack(std::string const & target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
};

#endif