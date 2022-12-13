/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:32:09 by airodrig          #+#    #+#             */
/*   Updated: 2021/12/26 14:52:04 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	mem_config(char **str)
{
	char	*aux;
	char	*check;

	aux = *str;
	check = ft_strchr(aux, '\n');
	if (check)
		*str = ft_strdup(check + 1);
	else
		*str = ft_strdup(NULL);
	free(aux);
	if (!(*str)[0])
	{
		free(*str);
		*str = NULL;
	}
}

char	*check_str(char **str, int i)
{
	char	*s;
	int		j;

	if (i <= 0 && !*str)
		return (NULL);
	j = 0;
	while (((*str)[j] && (*str)[j] != '\n'))
		j++;
	s = ft_calloc(sizeof(char), j + 2);
	j = -1;
	while ((*str)[++j] && (*str)[j] != '\n')
		s[j] = (*str)[j];
	if ((*str)[j] && (*str)[j] == '\n')
		s[j++] = '\n';
	s[j] = '\0';
	mem_config(str);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*rt = NULL;
	char		*buf;
	char		*aux;
	int			i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!rt || !ft_strchr(rt, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i <= 0)
			break ;
		buf[i] = '\0';
		if (!rt)
			rt = ft_calloc(1, sizeof(char));
		aux = rt;
		rt = ft_strjoin(aux, buf);
		free(aux);
	}
	free(buf);
	return (check_str(&rt, i));
}
