/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:09:05 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/22 13:43:49 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class	Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain();
		Brain(Brain &brain);
		~Brain();
		Brain	&operator=(Brain const &brain);

		std::string	*getideas() const;
};

#endif
