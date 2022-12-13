/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:59:32 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/11 14:44:33 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	cnt;
	char	*srcc;
	char	*destc;

	cnt = -1;
	srcc = (char *)src;
	destc = dest;
	if (src == dest)
		return (dest);
	else if (src < dest)
	{
		while (n--)
			destc[n] = srcc[n];
	}
	else
	{
		while (++cnt < n)
			destc[cnt] = srcc[cnt];
	}
	return (dest);
}
