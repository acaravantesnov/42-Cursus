/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:59:45 by acaravan          #+#    #+#             */
/*   Updated: 2021/05/05 20:24:51 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
}
