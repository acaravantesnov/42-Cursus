/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:31:43 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/22 12:31:55 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmps(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	return (ft_strncmp(s1, s2, INT_MAX) || \
	ft_strlen(s1) != ft_strlen(s2));
}

short	ft_cinstr(char c, char *str)
{
	while (str && *str)
		if (*(str++) == c)
			return (1);
	return (0);
}
