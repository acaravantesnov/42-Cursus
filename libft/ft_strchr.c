/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:24:31 by acaravan          #+#    #+#             */
/*   Updated: 2021/02/06 01:32:28 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
		{
			return ((char *)s);
			break ;
		}
		else if ((*s == '\0') && (c == '\0'))
			return ((char *)s);
		s++;
	}
	if ((c == 0) && (*s == '\0'))
		return ((char *)s);
	return (NULL);
}
