/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:17:45 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/15 23:45:47 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		cnt;
	int		cntstr;

	cnt = 0;
	cntstr = 0;
	if (!s || !f)
		return (NULL);
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[cnt])
	{
		str[cntstr] = f(cnt, s[cnt]);
		cnt++;
		cntstr++;
	}
	str[cntstr] = '\0';
	return (str);
}
