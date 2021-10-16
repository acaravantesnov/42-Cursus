/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 17:16:49 by acaravan          #+#    #+#             */
/*   Updated: 2021/05/08 15:38:32 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inicio(char const *s1, char const *s2);
static int	ft_final(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		begin;
	int		end;
	int		count;

	if (!s1 || !set)
		return (NULL);
	begin = ft_inicio(s1, set);
	end = ft_final(s1, set);
	count = end - begin;
	result = (char *)malloc((count + 2) * sizeof(char));
	if (!result)
		return (0);
	count = 0;
	if (begin + end >= 0)
	{
		while (begin <= end)
		{
			result[count] = s1[begin];
			begin++;
			count++;
		}
	}
	result[count] = '\0';
	return (result);
}

static int	ft_inicio(char const *s1, char const *s2)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	while (s2[count2])
	{
		if (s2[count2] != s1[count])
			count2++;
		else if (s1[count + 1])
		{
			count++;
			count2 = 0;
		}
		else
			return (-1);
	}
	return (count);
}

static int	ft_final(char const *s1, char const *s2)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 0;
	while (s1[count])
		count++;
	count--;
	while (s2[count2])
	{
		if (s2[count2] != s1[count])
			count2++;
		else if (count > 0)
		{
			count--;
			count2 = 0;
		}
		else
			return (-1);
	}
	return (count);
}
