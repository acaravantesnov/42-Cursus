/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:07:19 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/16 18:55:12 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	cnt;
	unsigned int	size;

	cnt = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		size = 0;
	else if (start + len > ft_strlen(s))
		size = ft_strlen(s) - start;
	else
		size = len;
	substr = malloc(size + 1);
	if (!substr)
		return (NULL);
	while (s[start] && cnt < size)
		substr[cnt++] = s[start++];
	substr[cnt] = '\0';
	return (substr);
}
