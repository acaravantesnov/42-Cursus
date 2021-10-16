/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:35:34 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/10 13:56:40 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if ((nb > -2147483648) || (nb <= 2147483647))
	{
		if (nb == -2147483648)
		{
			ft_putchar(45);
			ft_putchar('2');
			ft_putnbr(147483648);
		}
		else if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else if (nb < 0)
		{
			nb *= (-1);
			ft_putchar(45);
			ft_putnbr(nb);
		}
		else
		{
			ft_putchar(nb + 48);
		}
	}
}
