/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:03:19 by aidasmiler        #+#    #+#             */
/*   Updated: 2021/09/11 12:10:55 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	cnt;
	char	*sconv;

	sconv = s;
	cnt = 0;
	while (cnt < n)
	{
		sconv[cnt] = c;
		cnt++;
	}
	return ((void *)sconv);
}
