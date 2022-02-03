/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:06:40 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/03 14:18:28 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	*ft_calloc(int size)
{
	int	x;
	int	*ptr;

	x = 0;
	ptr = malloc(sizeof(int) * size);
	while (x < size)
	{
		ptr[x] = 0;
		x++;
	}
	return (ptr);
}
