/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:35:10 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/12 01:09:50 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	cnt;
	char	*srcc;
	char	*destc;

	cnt = 0;
	if (!dest && !src)
		return (NULL);
	srcc = (char *)src;
	destc = dest;
	while (cnt < n)
	{
		destc[cnt] = srcc[cnt];
		cnt++;
	}
	return (dest);
}
