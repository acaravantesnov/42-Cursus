/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:50:29 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/18 16:17:58 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *str, char c)
{
	int	cnt;
	int	nwords;
	int	issep;

	cnt = 0;
	nwords = 0;
	issep = 0;
	while (str[cnt] && str[cnt] == c)
		cnt++;
	while (str[cnt])
	{
		if (!issep && str[cnt] == c)
		{
			issep = 1;
			nwords++;
		}
		else if (str[cnt] != c)
			issep = 0;
		cnt++;
	}
	if (cnt && str[cnt - 1] && str[cnt - 1] == c)
		nwords--;
	if (cnt != 0 && !str[cnt])
		nwords++;
	return (nwords);
}

static int	ft_countchars(char const *s, char c)
{
	int	n;

	n = 0;
	while (s[n] && s[n] != c)
		n++;
	return (n);
}

static void	ft_advthis(char const *s, char c, int *n)
{
	while (s[*n] && s[*n] == c)
		(*n)++;
}

static char	**ft_freemysplt(char **splitted, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(splitted[i++]);
	free(splitted);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		cnt;
	int		cntcpy;
	int		n;

	cnt = 0;
	n = 0;
	if (!s)
		return (NULL);
	splitted = ft_calloc((ft_countwords(s, c) + 1), sizeof(char *));
	if (!splitted)
		return (NULL);
	ft_advthis(s, c, &cnt);
	while (s[cnt])
	{
		cntcpy = 0;
		splitted[n] = ft_calloc(ft_countchars(&s[cnt], c) + 1, sizeof(char));
		if (!(splitted[n]))
			return (ft_freemysplt(splitted, n));
		while (s[cnt] && (s[cnt]) != c)
			splitted[n][cntcpy++] = s[cnt++];
		n++;
		ft_advthis(s, c, &cnt);
	}
	return (splitted);
}
