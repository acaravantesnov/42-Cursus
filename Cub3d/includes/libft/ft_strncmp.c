/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:26:01 by acaravan          #+#    #+#             */
/*   Updated: 2021/04/29 19:30:29 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	while (n > 0)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		if ((unsigned char)*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}
