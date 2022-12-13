/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:25:21 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/15 23:47:18 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		cnt1;
	int		cnt2;

	cnt1 = -1;
	cnt2 = -1;
	if (!s1 || !s2)
		return (NULL);
	s = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	while (s1[++cnt1])
		s[cnt1] = s1[cnt1];
	while (s2[++cnt2])
	{
		s[cnt1] = s2[cnt2];
		cnt1++;
	}
	s[cnt1] = '\0';
	return (s);
}
