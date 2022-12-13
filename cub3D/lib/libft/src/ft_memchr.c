/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 15:35:08 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/11 16:35:54 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cnt;
	unsigned char	*sc;

	cnt = 0;
	sc = (unsigned char *)s;
	while (cnt < n)
	{
		if (sc[cnt] == (unsigned char)c)
			return ((void *)&sc[cnt]);
		cnt++;
	}
	return (NULL);
}
