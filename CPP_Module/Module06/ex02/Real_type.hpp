/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Real_type.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 23:12:28 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/19 23:21:37 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <cstdlib>
# include <iostream>

class	Base
{
	public:
		virtual	~Base();
};

class	A : public Base {};
class	B : public Base {};
class	C : public Base {};

Base	*generate(void);
void	identify(Base *p);

#endif
