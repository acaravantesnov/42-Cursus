/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:29:16 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/21 13:55:02 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>
# include <string>

class	ICharacter;

class	AMateria
{
	protected:
		std::string	type;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria &amateria);
		virtual ~AMateria();
		virtual AMateria	&operator=(AMateria const &amateria);

		std::string const & getType() const; //Returns the materia type
		
		virtual	AMateria* clone() const = 0;
		virtual	void use(ICharacter& target);
};

#endif
