/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:24:37 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/12 12:42:17 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			cnt;
	const size_t	srclen = ft_strlen(src);

	cnt = 0;
	if (!size)
		return (srclen);
	while (src[cnt] && (cnt < size - 1))
	{
		dst[cnt] = src[cnt];
		cnt++;
	}
	dst[cnt] = '\0';
	return (srclen);
}
