/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 12:13:34 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/11 13:31:31 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	cnt;
	char	*szeros;

	szeros = s;
	cnt = 0;
	while (cnt < n)
	{
		szeros[cnt] = '\0';
		cnt++;
	}
}
