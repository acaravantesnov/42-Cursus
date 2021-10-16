/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 20:28:19 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/05 09:40:20 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		check_buffer(char *pos, char **line);
char	*get_next_line(int fd);
char	*freeandreturn(char *line);

#endif