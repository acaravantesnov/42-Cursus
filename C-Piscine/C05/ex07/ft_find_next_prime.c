/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:35:42 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/14 15:25:27 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb);

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return (nb);
	else if (ft_is_prime(nb) == 0)
	{
		nb++;
		return (ft_find_next_prime(nb));
	}
	return (0);
}

int	ft_is_prime(int nb)
{
	int		i;
	float	x;

	i = 2;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (ft_is_prime(i) == 1)
	{
		while (i < nb)
		{
			if (nb % i == 0)
				return (0);
			else
			{
				x = nb / i;
				if (x < 1)
					return (1);
			}
			i++;
		}
	}
	return (1);
}
