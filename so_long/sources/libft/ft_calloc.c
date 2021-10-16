/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:29:37 by acaravan          #+#    #+#             */
/*   Updated: 2021/02/06 13:26:35 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*ptr;
	char		*start;
	size_t		i;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	start = ptr;
	while (i < (count * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (start);
}
