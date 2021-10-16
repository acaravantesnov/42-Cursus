/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:01:54 by acaravan          #+#    #+#             */
/*   Updated: 2021/04/29 19:41:58 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		cifras;
	long	n1;
	char	*num;

	n1 = n;
	cifras = ft_cifras(n1);
	if ((long)n == 2147483648)
		return (ft_substr("2147483648", 0, 12));
	else if ((long)n == -2147483648)
		return (ft_substr("-2147483648", 0, 12));
	if (n >= 0)
		num = (char *)malloc(sizeof(char) * (cifras + 1));
	else
	{
		num = (char *)malloc(sizeof(char) * (cifras + 2));
		(n1 *= (-1));
	}
	if (num == NULL)
		return (NULL);
	ft_while_itoa(cifras, n1, num);
	if (n < 0)
		return (ft_avanzar(cifras, n, num));
	else
		return (num);
}
