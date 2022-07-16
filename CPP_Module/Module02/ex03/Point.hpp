
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:15:25 by acaravan          #+#    #+#             */
/*   Updated: 2022/03/03 15:58:16 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class	Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(const float &x, const float &y);
		Point(const Point &point);
		~Point();
		Point	&operator=(const Point &f);

		Fixed	getX() const;
		Fixed	getY() const;
};

#endif
