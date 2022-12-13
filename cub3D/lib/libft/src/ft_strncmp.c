/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:01:23 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/12 14:13:27 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < n && (s1[cnt] == s2 [cnt]) && s1[cnt] && s2[cnt])
		cnt++;
	if (cnt == n)
		return (0);
	return ((unsigned char)s1[cnt] - (unsigned char)s2[cnt]);
}
