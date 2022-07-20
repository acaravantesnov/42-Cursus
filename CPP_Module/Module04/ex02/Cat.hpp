/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:12:47 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/20 15:58:25 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain	*_Brainptr;
	public:
		Cat();
		Cat(Cat &cat);
		virtual ~Cat();
		Cat	&operator=(Cat const &cat);

		Brain*			getBrainptr() const;
		virtual void	makeSound() const;
};

#endif
