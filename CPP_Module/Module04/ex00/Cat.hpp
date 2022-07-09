/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:12:47 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/09 21:01:14 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		Cat(Cat &cat);
		~Cat();

		virtual void	makeSound() const;
};

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat &wrongcat);
		~WrongCat();
};

#endif
