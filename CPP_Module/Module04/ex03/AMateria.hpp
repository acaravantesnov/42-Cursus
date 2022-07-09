/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:29:16 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 17:20:26 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>

class	AMateria
{
	protected:
		std::string	type;
	public:
		AMateria(std::string const & type);
		AMateria();
		AMateria(AMateria &amateria);
		~AMateria();

		std::string const & getType() const; //Returns the materia type
		
		virtual	AMateria* clone() const = 0;
		virtual	void use(ICharacter& target);
};

#endif
