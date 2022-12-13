/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:52:11 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/15 23:42:43 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	cnt;

	cnt = 0;
	if (!s || !f)
		return ;
	while (s[cnt])
	{
		f(cnt, &s[cnt]);
		cnt++;
	}
}
