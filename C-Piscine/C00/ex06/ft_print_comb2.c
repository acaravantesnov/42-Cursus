/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:46:38 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/15 15:25:44 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	sustituir(int n1, int n2)
{
	ft_putchar((n1 / 10) + 48);
	ft_putchar((n1 % 10) + 48);
	ft_putchar(' ');
	ft_putchar((n2 / 10) + 48);
	ft_putchar((n2 % 10) + 48);
}

void	ft_print_comb2(void)
{
	int n1;
	int n2;

	n1 = 0;
	n2 = 1;
	while (n1 <= 98 && n2 <= 100)
	{
		if (n2 == 100)
		{
			n1++;
			n2 = n1 + 1;
		}
		else
		{
			sustituir(n1, n2);
			if (n1 != 98)
			{
				ft_putchar(44);
				ft_putchar(' ');
			}
			n2++;
		}
	}
}
