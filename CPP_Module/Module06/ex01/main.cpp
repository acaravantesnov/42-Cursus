/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:16:57 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/19 23:52:45 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"
#include <iostream>

int	main()
{
	Data		*data;
	Data		*data2;
	uintptr_t	info;

	data = new Data(false);
	info = serialize(data);
	data2 = deserialize(info);
	std::cout << data2->_data << std::endl;
	return (0);
}

