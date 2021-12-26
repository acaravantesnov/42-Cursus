/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:09:12 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/26 12:11:15 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	*ft_realloc(long *ptr, int originSize, int newSize)
{
	int	i;
	long	*temp;

	i = 0;
	if (ptr != NULL)
	{
		temp = ptr;
		while (i < originSize)
		{
			ptr++;
			i++;
		}
		ptr = malloc(sizeof(long) * (newSize - originSize));
		return (temp);
	}
	return (NULL);
}
