/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:12:15 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/22 12:10:47 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *str, char *c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (str[i] && ft_cinstr(str[i], c))
		i++;
	while (str[i])
	{
		while (str[i] && !ft_cinstr(str[i], c))
			i++;
		while (str[i] && ft_cinstr(str[i], c))
			i++;
		cnt++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char *c)
{
	char	**ret_arr;
	int		beg;
	int		end;
	int		i;

	beg = 0;
	end = 0;
	i = 0;
	if (!s)
		return (NULL);
	ret_arr = malloc((ft_count(s, c) + 1) * sizeof(char *));
	while (s[end] && ft_cinstr(s[end], c))
		beg = ++end;
	while (s[end])
	{
		while (!ft_cinstr(s[end], c) && s[end])
			end++;
		ret_arr[i] = ft_substr((char *)s, beg, end - beg);
		while (s[end] && ft_cinstr(s[end], c))
			beg = ++end;
		i++;
	}
	ret_arr[i] = NULL;
	return (ret_arr);
}
