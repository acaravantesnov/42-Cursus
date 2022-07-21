/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:40:35 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/21 13:45:40 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
		public:
			MateriaSource();
			MateriaSource(MateriaSource const &materiasource);
			~MateriaSource();
			MateriaSource	&operator=(MateriaSource const &materiasource);

			virtual void learnMateria(AMateria*);
			virtual AMateria* createMateria(std::string const & type);
};

#endif