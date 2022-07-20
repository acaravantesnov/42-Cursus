/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:50:37 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/20 15:45:07 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal &wronganimal);
		~WrongAnimal();
		WrongAnimal	&operator=(WrongAnimal const &wronganimal);

		void	makeSound() const;
};

#endif
