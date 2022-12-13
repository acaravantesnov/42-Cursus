/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:09:39 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/16 14:48:43 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	nb;
	int					cnt;
	int					isneg;

	nb = 0;
	cnt = 0;
	isneg = 1;
	while (str[cnt] == ' ' || str[cnt] == '\t' || str[cnt] == '\n'
		|| str[cnt] == '\v' || str[cnt] == '\f' || str[cnt] == '\r')
		cnt++;
	if (str[cnt] == '+' || str[cnt] == '-')
	{
		if (str[cnt] == '-')
			isneg = -1;
		cnt++;
	}
	while (str[cnt] && str[cnt] >= '0' && str[cnt] <= '9')
		nb = nb * 10 + str[cnt++] - '0';
	if (isneg == -1 && nb > LONG_MAX)
		return (0);
	if (isneg == 1 && nb > LONG_MAX)
		return (-1);
	return (nb * isneg);
}
