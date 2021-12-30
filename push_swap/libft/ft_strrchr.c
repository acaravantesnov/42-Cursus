/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:25:00 by acaravan          #+#    #+#             */
/*   Updated: 2021/02/09 23:21:51 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		save;
	char	*ret;

	i = 0;
	save = -1;
	ret = (char *)s;
	while (*s)
	{
		if (*s == c)
			save = i;
		s++;
		i++;
	}
	if (c == 0)
		return ((char *)s);
	else if (save == -1)
		return (NULL);
	i = 0;
	while (i < save)
	{
		i++;
		ret++;
	}
	return (ret);
}
