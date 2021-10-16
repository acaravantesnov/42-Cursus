/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:17:12 by acaravan          #+#    #+#             */
/*   Updated: 2021/08/15 18:06:29 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_pointer(unsigned long n)
{
	int	cont;

	cont = 0;
	cont += write(1, "0x", 2);
	if (n != 0)
		cont += ft_putnbr_base2(n, "0123456789abcdef");
	else
		cont += write(1, "0", 1);
	return (cont);
}
