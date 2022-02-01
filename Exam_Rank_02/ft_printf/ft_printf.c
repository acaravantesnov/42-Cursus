/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:34:02 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/02 00:23:15 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

size_t	ft_strlen(const char *s)
{
	size_t i = 0;
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

void	ft_print_num(long long num, int base_l, char *base)
{
	if (num >= base_l)
		ft_print_num(num / base_l, base_l, base);
	write(1, &base[num%base_l], 1);
}

int	ft_printf(const char *input, ...)
{
	
}

int	main()
{
	ft_printf("Hola%% bb");
	return (0);
}