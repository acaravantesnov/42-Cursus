/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:46:37 by aidasmiler        #+#    #+#             */
/*   Updated: 2021/09/12 13:52:59 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			cntdst;
	size_t			cntsrc;
	const size_t	dstlen = ft_strlen(dst);
	const size_t	srclen = ft_strlen(src);

	cntdst = 0;
	cntsrc = 0;
	if (size <= dstlen)
		return (srclen + size);
	while (dst[cntdst])
		cntdst++;
	while (src[cntsrc] && (cntsrc < size - dstlen - 1))
		dst[cntdst++] = src[cntsrc++];
	if (dstlen + cntsrc < size)
		dst[cntdst] = '\0';
	return (dstlen + srclen);
}
