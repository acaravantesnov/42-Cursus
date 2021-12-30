/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:09:12 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/29 14:18:30 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_realloc(long *ptr, int originSize, int newSize)
{
	int		i;
	long	*temp;

	i = 0;
	if ((ptr != NULL) && (originSize < newSize))
	{
		temp = malloc(sizeof(long) * (newSize));
		while (i < originSize)
		{
			temp[i] = ptr[i];
			i++;
		}
		ptr = temp;
	}
	else if ((ptr != NULL) && (originSize > newSize))
	{
		temp = malloc(sizeof(long) * (newSize));
		while (i < newSize)
		{
			temp[i] = ptr[i];
			i++;
		}
		ptr = temp;
	}
}
