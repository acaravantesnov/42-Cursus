/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 06:03:42 by acaravan          #+#    #+#             */
/*   Updated: 2021/08/14 20:12:40 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_ifs(const char *input, int i, int ret, va_list(ap))
{
	if (input[i + 1] == '%')
		ret += write(1, "%", 1);
	else if ((input[i + 1] == 'i') || (input[i + 1] == 'd'))
		ret += ft_putnbr(va_arg(ap, int));
	else if (input[i + 1] == 'c')
		ret += ft_putchar(va_arg(ap, int));
	else if (input[i + 1] == 's')
		ret += ft_putstr(va_arg(ap, char *));
	else if (input[i + 1] == 'x')
		ret += ft_putnbr_base(va_arg(ap, int), "0123456789abcdef");
	else if (input[i + 1] == 'X')
		ret += ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
	else if (input[i + 1] == 'u')
		ret += ft_putunbr(va_arg(ap, unsigned int));
	else if (input[i + 1] == 'p')
		ret += ft_pointer(va_arg(ap, size_t));
	return (ret);
}

int	ft_printfext(int i, int ret, const char *input, va_list(ap))
{
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			ret = ft_ifs(input, i, ret, ap);
			i++;
		}
		else
			ret += write(1, &input[i], 1);
		i++;
	}
	return (ret);
}
