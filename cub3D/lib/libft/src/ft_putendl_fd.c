/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:09:12 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/15 23:44:18 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	cnt;

	cnt = 0;
	if (!s)
		return ;
	while (s[cnt])
	{
		write(fd, &s[cnt], 1);
		cnt++;
	}
	write(fd, "\n", 1);
}
