/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 01:57:22 by acaravan          #+#    #+#             */
/*   Updated: 2022/07/20 22:29:32 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

#define N 10

void	print(const int &n)
{
	std::cout << n << std::endl;
}

void	even_or_odd(const int &n)
{
	if (n % 2 == 0)
		std::cout << "even" << std::endl;
	else
		std::cout << "odd" << std::endl;
}

int main(void)
{
	srand(time(NULL));

	int	arr[N];
	for (int i = 0; i < N; i++)
		arr[i] = (rand()%N) + 1;

	int	*arrptr = arr;
	void	(*funcptr)(const int &) = &print;
	iter(arrptr, N, print);
	std::cout << std::endl;
	iter(arrptr, N, even_or_odd);
	return (0);
}

/*
class Awesome
{
	public:
		Awesome( void ) : _n(42) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main() {
	int tab[] = { 0, 1, 2, 3, 4 }; // <--- Qué sentido tiene no poder escribir int[] tab. No sería más simple??
	Awesome tab2[5];
	iter( tab, 5, print );
	iter( tab2, 5, print );

	return 0;
}
*/
