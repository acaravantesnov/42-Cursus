/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 11:43:44 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/16 14:54:20 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(char *a, char *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

static void	ft_rev_str(char *str, int size)
{
	int	cnt;

	cnt = 0;
	while (cnt < size)
	{
		ft_swap(&str[cnt], &str[size - 1]);
		cnt++;
		size--;
	}
}

static int	ft_isneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	ft_ndigits(int n)
{
	int	ndigits;

	ndigits = 0;
	if (n < 0)
		ndigits++;
	else if (!n)
		ndigits++;
	while (n != 0)
	{
		ndigits++;
		n /= 10;
	}
	return (ndigits);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		cnt;
	int		isneg;

	cnt = 0;
	number = malloc(ft_ndigits(n) + 1);
	if (!number)
		return (NULL);
	isneg = ft_isneg(n);
	if (n == 0)
		number[cnt++] = '0';
	while (n != 0)
	{
		if ((n % 10) > 0)
			number[cnt++] = (n % 10) + '0';
		else
			number[cnt++] = ((n % 10) * -1) + '0';
		n /= 10;
	}
	if (isneg)
		number[cnt++] = '-';
	number[cnt] = '\0';
	ft_rev_str(number, ft_strlen(number));
	return (number);
}
