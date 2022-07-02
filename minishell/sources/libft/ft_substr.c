/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:59:45 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/12 21:26:43 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	char			*inicio;
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	inicio = ptr;
	while (*s && (i < start))
	{
		i++;
		s++;
	}
	while ((i >= start) && ((i - start) < len))
	{
		*ptr = *s;
		ptr++;
		s++;
		i++;
	}
	*ptr = '\0';
	return (inicio);
}*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*return_string;

	if (!s)
		return (NULL);
	if (ft_strlen((char *)s) < start)
	{
		return_string = malloc(sizeof(char));
		*return_string = 0;
		return (return_string);
	}
	i = 0;
	while (s[start + i] && i < len)
		i++;
	return_string = malloc((i + 1) * sizeof(char));
	if (return_string == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		return_string[i] = s[start + i];
		i++;
	}
	return_string[i] = 0;
	return (return_string);
}
