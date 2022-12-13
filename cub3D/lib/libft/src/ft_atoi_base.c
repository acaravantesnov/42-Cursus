/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:01:40 by airodrig          #+#    #+#             */
/*   Updated: 2022/02/05 19:10:14 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contains_signs(char *str, char to_find)
{
	int	str_cnt;
	int	to_find_cnt;

	str_cnt = 0;
	to_find_cnt = 0;
	if (!to_find)
		return (0);
	while (str[str_cnt])
	{
		if (str[str_cnt] == to_find)
			to_find_cnt++;
		str_cnt++;
	}
	if (to_find_cnt > 0)
		return (1);
	else
		return (0);
}

static int	same_chars(char *str)
{
	int	cnt1;
	int	cnt2;

	cnt1 = 0;
	while (str[cnt1])
	{
		cnt2 = cnt1 + 1;
		while (str[cnt2])
		{
			if (str[cnt1] == str[cnt2])
				return (1);
			cnt2++;
		}
		cnt1++;
	}
	return (0);
}

static int	ft_minuses_isspace(char *str, int *p_cnt)
{
	int	minuses;

	minuses = 0;
	while (str[*p_cnt] == ' ' || str[*p_cnt] == '\t' || str[*p_cnt] == '\n'
		|| str[*p_cnt] == '\v' || str[*p_cnt] == '\f' || str[*p_cnt] == '\r')
		(*p_cnt)++;
	while (str[*p_cnt] == '-' || str[*p_cnt] == '+')
	{
		if (str[*p_cnt] == '-')
			minuses++;
		(*p_cnt)++;
	}
	return (minuses);
}

/*int	ft_base_contains_nbs(char *str, char *base)
{
	int	cnt1;
	int	cnt2;

	cnt1 = 0;
	while (str[cnt1])
	{
		cnt2 = cnt1 + 1;
		while (str[cnt1] != base[cnt2] && base[cnt2])
			cnt2++;
		if (!base[cnt2])


	}
	if (ft_strlen(base) == cnt2)
		return (1);
	return (0);

}*/

int	ft_atoi_base(char *str, char *base)
{
	int				cnt;
	int				nb;
	unsigned int	length;
	int				minuses;

	nb = 0;
	cnt = 0;
	minuses = ft_minuses_isspace(str, &cnt);
	length = ft_strlen(base);
	if (length > 1 && !contains_signs(base, '+') && !contains_signs(base, '-')
		&& !contains_signs(base, ' ') && !same_chars(base))
	{
		while (str[cnt])
		{
			nb = nb * length + str[cnt] - '0';
			cnt++;
		}
		if (minuses % 2 == 1)
			nb *= -1;
		return (nb);
	}
	return (0);
}
