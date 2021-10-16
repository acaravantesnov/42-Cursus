/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 11:22:31 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/13 11:26:59 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *ptr;
	int *start;
	int i;

	ptr = malloc(sizeof(int) * (max - min));
	start = ptr;
	i = 0;
	while(i < (max - min))
	{
		*ptr = min + i;
		i++;
		ptr++;
	}
	return (start);
}
