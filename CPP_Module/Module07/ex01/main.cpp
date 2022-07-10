/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:57:22 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/10 14:28:06 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define N 10

void	myfunc(int n)
{
	n *= 2;
	std::cout << n << std::endl;
}

int main(void)
{
	int	arr[N];
	for (int i = 1; i <= N; i++)
		arr[i - 1] = i;
	int	*arrptr = arr;
	void	(*funcptr)(int) = &myfunc;
	iter<int>(arrptr, N, funcptr);

	return (0);
}
