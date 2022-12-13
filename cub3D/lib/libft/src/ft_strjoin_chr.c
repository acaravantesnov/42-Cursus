/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_chr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:36:11 by airodrig          #+#    #+#             */
/*   Updated: 2022/05/04 10:37:04 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strjoin_chr(char *str, char c)
{
	char	*rt;
	int		i;

	i = -1;
	rt = ft_calloc((ft_strlen(str) + 2), sizeof(char));
	if (!rt)
		return (NULL);
	while (str[++i])
		rt[i] = str[i];
	rt[i] = c;
	free(str);
	return (rt);
}
