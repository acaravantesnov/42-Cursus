/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:38:23 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/12 00:56:43 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			cnt;
	unsigned char	*s1c;
	unsigned char	*s2c;

	cnt = 0;
	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	if (!n)
		return (0);
	while (cnt < n)
	{
		if (s1c[cnt] != s2c[cnt])
			return ((s1c[cnt] - s2c[cnt]));
		cnt++;
	}
	return ((s1c[cnt - 1] - s2c[cnt - 1]));
}
