/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:15:31 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/16 18:32:58 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*haystack, const char *needle, size_t len)
{
	size_t	cnth;
	size_t	cntn;

	if (!*needle)
		return ((char *)haystack);
	cnth = 0;
	while (haystack[cnth] && cnth < len)
	{
		cntn = 0;
		while ((cntn + cnth) < len && haystack[cnth + cntn] == needle[cntn])
		{
			if (!needle[cntn + 1])
				return ((char *)&haystack[cnth]);
			cntn++;
		}
		cnth++;
	}
	return (NULL);
}
