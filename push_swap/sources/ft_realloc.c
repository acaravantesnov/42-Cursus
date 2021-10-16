/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:09:12 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/20 07:27:47 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*ft_realloc(int *ptr, int originSize, int newSize)
{
	int	i;
	int	*temp;

	i = 0;
	if (ptr != NULL)
	{
		temp = ptr;
		while (i < originSize)
		{
			ptr++;
			i++;
		}
		ptr = malloc(sizeof(int) * (newSize - originSize));
		return (temp);
	}
	return (NULL);
}
