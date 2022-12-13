/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 18:46:31 by aidasmiler        #+#    #+#             */
/*   Updated: 2021/09/16 17:05:08 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] && s[cnt] != (unsigned char)c)
		cnt++;
	if (s[cnt] == (unsigned char)c)
		return ((char *)&s[cnt]);
	return (NULL);
}
