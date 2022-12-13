/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:51:45 by airodrig          #+#    #+#             */
/*   Updated: 2021/12/26 14:51:45 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			cnt;
	unsigned char	*srcc;
	unsigned char	*destc;
	unsigned char	ccpy;

	cnt = 0;
	srcc = (unsigned char *)src;
	destc = dest;
	ccpy = (unsigned char) c;
	while (cnt < n)
	{
		destc[cnt] = srcc[cnt];
		if (srcc[cnt] == ccpy)
			return (&destc[cnt + 1]);
		cnt++;
	}
	return (NULL);
}
