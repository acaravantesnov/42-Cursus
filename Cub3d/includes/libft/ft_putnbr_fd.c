/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:41:35 by acaravan          #+#    #+#             */
/*   Updated: 2021/02/07 19:56:34 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if ((n >= -2147483648) || (n <= 2147483647))
	{
		if (n == -2147483648)
		{
			ft_putchar_fd(45, fd);
			ft_putchar_fd('2', fd);
			ft_putnbr_fd(147483648, fd);
		}
		else if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else if (n < 0)
		{
			n *= (-1);
			ft_putchar_fd(45, fd);
			ft_putnbr_fd(n, fd);
		}
		else
			ft_putchar_fd(n + 48, fd);
	}
}
