/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:01:43 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 18:29:40 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class	FragTrap: public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string	&Name);
		FragTrap(FragTrap &scavTrap);
		~FragTrap();

		FragTrap	&operator=(FragTrap &fragTrap2);
		void	highFivesGuys(void);
};

#endif
