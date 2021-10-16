/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 12:52:14 by acaravan          #+#    #+#             */
/*   Updated: 2021/05/05 20:19:18 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dstc;
	const char	*srcc;
	char		*dst2;
	const char	*src2;

	if (src == 0 && dst == 0)
		return (0);
	dstc = dst;
	srcc = src;
	if (dstc < srcc)
	{
		while (len--)
			*dstc++ = *srcc++;
	}
	else
	{
		dst2 = dstc + (len - 1);
		src2 = src + (len - 1);
		while (len--)
			*dst2-- = *src2--;
	}
	return (dst);
}
