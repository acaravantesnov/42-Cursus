/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:45:59 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/20 20:49:55 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

void	if1(int argc, char **argv, int *fd)
{
	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	check_args(argc, argv);
}

int	if2(char **argv, char **env, int *fd)
{
	int	pid1;
	int	fdreadfile;

	fdreadfile = open(argv[1], O_RDONLY, 0777);
	pid1 = fork();
	if (pid1 < 0)
		exitwitherror("PID ERROR");
	if (pid1 == 0)
	{
		if (fdreadfile == -1)
			exitwitherror("Error while opening file");
		dup2(fdreadfile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		execcmd(argv[2], env);
	}
	close(fdreadfile);
	return (pid1);
}

int	if3(char **argv, char **env, int *fd)
{
	int	pid2;
	int	fdwritefile;

	fdwritefile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	pid2 = fork();
	if (pid2 < 0)
		exitwitherror("PID ERROR");
	if (pid2 == 0)
	{
		if (fdwritefile == -1)
			exitwitherror("Error while opening file");
		dup2(fd[0], STDIN_FILENO);
		dup2(fdwritefile, STDOUT_FILENO);
		close(fd[1]);
		execcmd(argv[3], env);
	}
	close(fdwritefile);
	return (pid2);
}

int	main(int argc, char *argv[], char *env[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if1(argc, argv, fd);
	pid1 = if2(argv, env, fd);
	pid2 = if3(argv, env, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
