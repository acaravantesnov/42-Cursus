/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:49:28 by airodrig          #+#    #+#             */
/*   Updated: 2021/12/07 14:28:24 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;
	int		cnt;
	int		slen;

	slen = 0;
	if (s)
		slen = ft_strlen(s);
	sdup = malloc(slen + 1);
	if (!sdup)
		return (NULL);
	cnt = -1;
	while (++cnt < slen)
		sdup[cnt] = s[cnt];
	sdup[cnt] = '\0';
	return (sdup);
}
