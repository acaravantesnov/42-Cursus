/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:08:23 by acaravan          #+#    #+#             */
/*   Updated: 2021/08/14 19:47:17 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr(int n)
{
	int	cont;

	cont = 0;
	if ((n >= -2147483648) || (n <= 2147483647))
	{
		if (n == -2147483648)
		{
			cont += ft_putstr("-2");
			cont += ft_putnbr(147483648);
		}
		else if (n >= 10)
		{
			cont += ft_putnbr(n / 10);
			cont += ft_putnbr(n % 10);
		}
		else if (n < 0)
		{
			n *= (-1);
			cont += ft_putchar(45);
			cont += ft_putnbr(n);
		}
		else
			cont += ft_putchar(n + 48);
	}
	return (cont);
}
