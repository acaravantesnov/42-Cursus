/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 20:27:59 by acaravan          #+#    #+#             */
/*   Updated: 2021/08/15 15:56:40 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	cont;

	cont = 0;
	if ((n >= 0) || (n <= 4294967295))
	{
		if (n >= 10)
		{
			cont += ft_putnbr(n / 10);
			cont += ft_putnbr(n % 10);
		}
		else
			cont += ft_putchar(n + 48);
	}
	return (cont);
}
