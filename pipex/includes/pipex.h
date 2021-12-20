/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:17:19 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/19 20:32:24 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	exitwitherror(char *error);
void	check_args(int argc, char *argv[]);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*find_path(char *cmd, char *env[]);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char *str);
void execcmd(char *argv, char **env);
void	ft_freestr(char **str);


#endif