/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:30:18 by airodrig          #+#    #+#             */
/*   Updated: 2021/12/07 14:24:21 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*memalloc;
	size_t	cnt;

	cnt = 0;
	memalloc = malloc(count * size);
	if (!memalloc)
		return (NULL);
	while (cnt < count * size)
	{
		memalloc[cnt] = '\0';
		cnt++;
	}
	return ((void *)memalloc);
}
