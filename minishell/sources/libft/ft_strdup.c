/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:30:00 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/21 16:15:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*ptr;
	char	*start;

	if (!src)
		return (src);
	ptr = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (ptr == NULL)
		return (NULL);
	start = ptr;
	while (src && *src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (start);
}
