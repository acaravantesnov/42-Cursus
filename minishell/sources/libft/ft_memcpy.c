/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 13:54:19 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/05 21:47:35 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*one;
	unsigned char	*two;

	one = (unsigned char *)dst;
	two = (unsigned char *)src;
	if ((dst == NULL) && (src == NULL))
		return (NULL);
	while (n > 0)
	{
		*one = *two;
		one++;
		two++;
		n--;
	}
	return (dst);
}
