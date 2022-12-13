/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:52:56 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/16 19:31:37 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		len;

	if (s1)
	{
		len = ft_strlen(s1) + 1;
		while (*s1 && ft_strchr(set, *s1))
		{
			s1++;
			len--;
		}
		while (len > 1 && ft_strchr(set, s1[len - 2]))
			len--;
		strtrim = malloc(sizeof(char) * len);
		if (strtrim)
			(void)ft_strlcpy(strtrim, s1, len);
		return (strtrim);
	}
	else
		return (NULL);
}
