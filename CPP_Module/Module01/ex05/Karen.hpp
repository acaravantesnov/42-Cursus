/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:02:00 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/22 20:39:28 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>
# include <vector>

class Karen
{
	private:
		void	_debug( void );
		void	_info( void);
		void	_warning( void );
		void	_error( void );
	public:
		void	complain( std::string level );
};



/*typedef	struct	s_list {
	std::string	lev;
	void		(Karen::*f)();
}	t_search;*/

#endif