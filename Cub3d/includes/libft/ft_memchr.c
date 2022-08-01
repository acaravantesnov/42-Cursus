/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:05:10 by acaravan          #+#    #+#             */
/*   Updated: 2021/05/05 20:17:31 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*chr;

	chr = (unsigned char *)s;
	while (n > 0)
	{
		if (*chr == (unsigned char)c)
			return (chr);
		n--;
		chr++;
	}
	return (NULL);
}
