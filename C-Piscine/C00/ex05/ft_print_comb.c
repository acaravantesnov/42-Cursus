/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:29:43 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/15 15:46:19 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	sino(char *a, char *b, char *c)
{
	write(1, a, 1);
	write(1, b, 1);
	write(1, c, 1);
	if (*a != '7')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	b = '1';
	c = '2';
	while ((a <= '7') && (b <= '9') && (c <= ':'))
	{
		if (c == ':')
		{
			b++;
			c = b + 1;
		}
		if (b == '9')
		{
			a++;
			b = a;
		}
		else
		{
			sino(&a, &b, &c);
			c++;
		}
	}
}
