/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:26:30 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 12:27:44 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_zero(long *a);

long	ft_atoi(char *str)
{
	long	e[4];

	ft_zero(e);
	while ((str[e[0]] == ' ') || (str[e[0]] == '\t') || (str[e[0]] == '\n')
		|| (str[e[0]] == '\v') || (str[e[0]] == '\f') || (str[e[0]] == '\r'))
		e[0]++;
	while ((str[e[0]] == '+') || (str[e[0]] == '-'))
	{
		if (str[e[0]] == '-')
			e[2]++;
		e[1]++;
		e[0]++;
	}
	if (e[1] > 1)
		return (0);
	while ((str[e[0]] >= 48) && (str[e[0]] <= 57))
	{
		e[3] = (e[3] * 10) + (str[e[0]] - 48);
		e[0]++;
	}
	if (e[2] % 2 != 0)
		e[3] = e[3] * (-1);
	return (e[3]);
}

void	ft_zero(long *a)
{
	long	i;

	i = 0;
	while (i < 4)
	{
		a[i] = 0;
		i++;
	}
}
