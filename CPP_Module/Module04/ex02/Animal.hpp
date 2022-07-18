/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:42:46 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/18 17:04:38 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(Animal &animal);
		virtual ~Animal();
		Animal	&operator=(Animal const &animal);

		const std::string	getType() const;
		void				setType(std::string type);

		virtual void		makeSound() const = 0;
};

#endif
