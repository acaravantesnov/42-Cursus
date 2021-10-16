/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:30:00 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/23 02:42:08 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*ptr;
	char	*start;

	ptr = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (ptr == NULL)
		return (NULL);
	start = ptr;
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (start);
}
