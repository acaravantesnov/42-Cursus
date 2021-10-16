/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:28:01 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/05 08:42:55 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int		i;
	size_t	elementos;

	i = 0;
	elementos = 0;
	while (str[i] != '\0')
	{
		i++;
		elementos++;
	}
	return (elementos);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	ptr = malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int n)
{
	char	*ret;

	if (!s)
		return (NULL);
	ret = (char *)s;
	while (*ret != n)
	{
		if (*ret == '\0')
			return (NULL);
		ret++;
	}
	return (ret);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dst;

	dst = s;
	while (n > 0)
	{
		*dst = 0;
		dst++;
		n--;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst2;
	char	*src2;

	i = 0;
	dst2 = (char *)dst;
	src2 = (char *)src;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (NULL);
}
