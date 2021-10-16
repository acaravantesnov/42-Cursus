/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 03:11:35 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/05 18:58:26 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freeandreturn(char *line)
{
	free(line);
	return (NULL);
}

int	check_pos(char *pos, char **line)
{
	char	*aux;
	char	*otro;
	char	aux2[BUFFER_SIZE + 1];

	ft_bzero(aux2, BUFFER_SIZE);
	aux = ft_strchr(pos, '\n');
	otro = *line;
	if (aux)
	{
		*aux = '\0';
		*line = ft_strjoin(otro, pos);
		free(otro);
		ft_memcpy(aux2, aux + 1, ft_strlen(aux + 1));
		ft_bzero(pos, BUFFER_SIZE + 1);
		ft_memcpy(pos, aux2, ft_strlen(aux2));
		ft_bzero(aux2, BUFFER_SIZE + 1);
		otro = *line;
		*line = ft_strjoin(otro, "\n");
		free(otro);
		return (1);
	}
	*line = ft_strjoin(otro, pos);
	free(otro);
	ft_bzero(pos, BUFFER_SIZE + 1);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	pos[256][BUFFER_SIZE + 1];
	int			rd;

	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 || !line)
		return (freeandreturn(line));
	ft_bzero(line, BUFFER_SIZE + 1);
	if (check_pos(pos[fd], &line))
		return (line);
	rd = read(fd, pos[fd], BUFFER_SIZE);
	while (rd)
	{
		if (check_pos(pos[fd], &line))
			return (line);
		else if (rd == -1)
			return (freeandreturn(line));
		rd = read(fd, pos[fd], BUFFER_SIZE);
	}
	if (line[0] == '\0')
		return (freeandreturn(line));
	return (line);
}
