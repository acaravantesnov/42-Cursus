/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 14:12:15 by acaravan          #+#    #+#             */
/*   Updated: 2021/05/01 18:30:41 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_char(int k, char const *s, char c);
static int	ft_num_col(char const *s, char c);
static char	**ft_add_value(int i, char c, char *s, char **split);

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		cols;

	i = 0;
	if (!s)
		return (0);
	cols = ft_num_col(s, c);
	split = (char **)malloc(sizeof(char **) * (cols + 1));
	if (!split)
		return (0);
	split = ft_add_value(i, c, (char *)s, split);
	return (split);
}

static int	ft_num_char(int k, char const *s, char c)
{
	int	count;
	int	words;
	int	total;

	count = 0;
	total = 0;
	while (total <= k && s[count])
	{
		words = 0;
		while (s[count] == c && s[count])
			count++;
		while (s[count] != c && s[count])
		{
			words++;
			count++;
		}
		total++;
	}
	return (words);
}

static int	ft_num_col(char const *s, char c)
{
	int	count;
	int	n_col;

	count = 0;
	n_col = 0;
	while (s[count])
	{
		if (s[count] == c && s[count + 1] != c)
			n_col++;
		count++;
	}
	n_col++;
	return (n_col);
}

static char	**ft_add_value(int i, char c, char *s, char **split)
{
	int	j;
	int	k;
	int	fila;

	k = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		j = 0;
		fila = ft_num_char(k, s, c);
		split[k] = (char *)malloc(sizeof(char) * (fila + 1));
		if (!split[k])
			return (0);
		while (s[i] != c && s[i])
			split[k][j++] = s[i++];
		while (s[i] == c && s[i])
			i++;
		split[k][j] = '\0';
		k++;
	}
	split[k] = NULL;
	return (split);
}
