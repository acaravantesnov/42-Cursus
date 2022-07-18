/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:01:43 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/17 19:01:20 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class	ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string	&Name);
		ScavTrap(ScavTrap &scavTrap);
		~ScavTrap();
		ScavTrap	&operator=(ScavTrap &clapTrap);

		void guardGate();
};

#endif
