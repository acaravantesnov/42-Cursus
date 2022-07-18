/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:01:43 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/17 20:12:45 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class	FragTrap: virtual public ClapTrap
{
	protected:
		int			_Hitpoints;
		int			_AttackDamage;
	public:
		FragTrap();
		FragTrap(const std::string	&Name);
		FragTrap(FragTrap &fragTrap);
		~FragTrap();
		FragTrap	&operator=(FragTrap &fragTrap);

		int		&getHitpoints();
		int		&getAttackDamage();
		void	setHitpoints(int Hitpoints);
		void	setAttackDamage(int AttackDamage);

		void	highFivesGuys(void);
};

#endif
