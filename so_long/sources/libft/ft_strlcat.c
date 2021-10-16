/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 23:14:32 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/20 04:58:03 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	while (dst[j] != '\0')
		j++;
	while ((src[k]))
	{
		dst[j + k] = src[k];
		k++;
	}
	return (j + ft_strlen((char *)src));
}
