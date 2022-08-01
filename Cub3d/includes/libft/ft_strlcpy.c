/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:32:24 by acaravan          #+#    #+#             */
/*   Updated: 2021/05/05 19:33:30 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen((char *)src));
	i = 0;
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = 0;
	while (src[i])
		++i;
	return (i);
}
