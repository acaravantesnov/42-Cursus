/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:01:43 by acaravan          #+#    #+#             */
/*   Updated: 2022/04/11 13:08:13 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class	FragTrap: virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string	&Name);
		FragTrap(FragTrap const &scavTrap);
		~FragTrap();

		void	highFivesGuys(void);
};

#endif
