/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:12:47 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/08 18:52:19 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		~Cat();
		virtual void	makeSound() const;
};

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		virtual void	makeSound() const;
};

#endif
