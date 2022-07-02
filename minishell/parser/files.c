/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:04:23 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/30 17:55:17 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sighandler_heredoc(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	exit(-3);
}

int	heredoc(char *end)
{
	int		p[2];
	pid_t	pid;
	char	*line;
	int		status;

	pipe(p);
	pid = fork();
	if (pid != 0)
	{
		close (p[1]);
		wait(&status);
		return ((signed char)WEXITSTATUS(status));
	}
	signal(SIGINT, sighandler_heredoc);
	line = readline("> ");
	while (1)
	{
		if (line == NULL || (!ft_strncmp(line, end, INT_MAX) \
		&& ft_strlen(line) == ft_strlen(end)))
			exit(p[0]);
		write(p[1], line, ft_strlen(line));
		write(p[1], "\n", 1);
		line = readline("> ");
	}
}
