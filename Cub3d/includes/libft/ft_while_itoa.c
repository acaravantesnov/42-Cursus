/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:48:55 by acaravan          #+#    #+#             */
/*   Updated: 2021/05/04 17:29:43 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_while_itoa(int cifras, long n1, char *num)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i++ < cifras)
	{
		if ((cifras - j) > 0)
			num[cifras - j] = ((n1 / ft_pow(10, j - 1)) % 10) + 48;
		else
			num[cifras - j] = (n1 / ft_pow(10, j - 1)) + 48;
		j++;
	}
	num[cifras] = '\0';
	return (num);
}
