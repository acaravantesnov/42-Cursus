/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:44:09 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 16:29:20 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

# define N 10

int	main(void)
{
	Array<int> int_arr(N);
	for (int i = 0; i < N; i++)
		int_arr[i] = i;
	std::cout << "Integer array: " << int_arr;

	Array<float> float_arr(N);
	for (int i = 0; i < N; i++)
		float_arr[i] = i * 0.3;
	std::cout << "Float array: " << float_arr;

	Array<std::string> string_arr(4);
	string_arr[0] = "Lord";
	string_arr[1] = "of";
	string_arr[2] = "the";
	string_arr[3] = "rings";
	std::cout << "String array: " << string_arr;

	try { int_arr[-1]; }
	catch (std::exception e)
	{
		std::cout << "Invalid index" << std::endl;
		return (1);
	}
	return (0);	
}
