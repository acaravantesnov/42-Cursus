/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cifras.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 22:46:09 by acaravan          #+#    #+#             */
/*   Updated: 2021/05/04 17:33:48 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cifras(long n1)
{
	int		cifras;

	cifras = 1;
	if (n1 < 0)
		n1 *= (-1);
	while ((n1 / 10) > 0)
	{
		n1 /= 10;
		cifras++;
	}
	return (cifras);
}
