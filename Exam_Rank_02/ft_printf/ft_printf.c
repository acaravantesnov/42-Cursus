/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:34:02 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/03 13:33:36 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

size_t	ft_strlen(const char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_intlen(long long num, int base)
{
	int i = 1;
	while (num >= base || num <= -base)
	{
		num /= base;
		i++;
	}
	return (i);
}

void	ft_printnum(long long num, int base_l,  char* base)
{
	if (num >= base_l)
		ft_printnum(num/base_l, base_l, base);
	write(1, &base[num%base_l], 1);
}

int	ft_printf(const char *input, ...)
{
	int i = 0, j = 0, size = 0;
	va_list ap;
	va_start(ap, input);
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			if (input[i + 1] == 'd')
			{
				int num = va_arg(ap, int);
				if (num < 0)
				{
					size += write(1, "-", 1);
					num *= (-1);
				}
				size += ft_intlen(num, 10);
				ft_printnum(num, 10, "0123456789");
				i++;
			}
			if (input[i + 1] == 'x')
			{
				int num = va_arg(ap, int);
				if (num < 0)
				{
					size += write(1, "-", 1);
					num *= (-1);
				}
				size += ft_intlen(num, 16);
				ft_printnum(num, 16, "0123456789abcdef");
				i++;
			}
			if (input[i + 1] == 's')
			{
				char *s = va_arg(ap, char*);
				if (!s)
					size += write(1, "(null)", 6);
				j = 0;
				while (s[j] != '\0')
				{
					size += write(1, &s[j], 1);
					j++;
				}
				i++;
			}
		}
		else
			size += write(1, &input[i], 1);
		i++;
	}
	va_end(ap);
	return (size);
}

int main ()
{
    printf("----> Mio\n");
    printf("\n%d\n", ft_printf("holala %d %s %x", -12, "42\0", 12));
    printf("\n----> Original\n");
    printf("\n%d\n", printf("holala %d %s %x", -12, "42\0", 12));
    return(0);
}