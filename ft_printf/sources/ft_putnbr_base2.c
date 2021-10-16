/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 22:58:42 by acaravan          #+#    #+#             */
/*   Updated: 2021/08/14 19:47:18 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_base2(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base2(unsigned long nbr, char *base)
{
	int	chapuza[3];
	int	nbr_final[100];

	chapuza[2] = 0;
	chapuza[1] = 0;
	chapuza[0] = 0;
	if (check_base2(base))
	{
		while (base[chapuza[0]])
			chapuza[0]++;
		while (nbr)
		{
			nbr_final[chapuza[2]] = nbr % chapuza[0];
			nbr = nbr / chapuza[0];
			chapuza[2]++;
		}
		while (--chapuza[2] >= 0)
			chapuza[1] += ft_putchar(base[nbr_final[chapuza[2]]]);
	}
	return (chapuza[1]);
}
