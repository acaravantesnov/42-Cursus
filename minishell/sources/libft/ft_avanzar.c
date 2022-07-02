/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avanzar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:40:33 by acaravan          #+#    #+#             */
/*   Updated: 2021/05/04 17:34:23 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_avanzar(int cifras, int n, char *num)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (n < 0)
	{
		while (i++ < (cifras + 1))
		{
			num[cifras + j] = num[cifras + (j - 1)];
			j--;
		}
		num[0] = 45;
	}
	return (num);
}
