/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 02:10:42 by acaravan          #+#    #+#             */
/*   Updated: 2022/03/18 21:23:51 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class	Zombie
{
	private:
		std::string	_name;
	public:
		Zombie() {}
		~Zombie();
		Zombie(std::string name);
		void		announce();
		void		randomChump( std::string name );
		void		setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
