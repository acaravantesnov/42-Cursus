/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:45:59 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/19 20:23:57 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	int fd[2];
	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	check_args(argc, argv);

	int pid1 = fork();
	if (pid1 < 0)
		exitwitherror("PID ERROR");
	if (pid1 == 0)
	{
		int fdreadfile = open(argv[1], O_RDONLY, 0777);
		if (fdreadfile == -1)
			exitwitherror("Error while opening file");
		dup2(fdreadfile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		execcmd(argv[2], env);
		close(fdreadfile);
	}

	int pid2 = fork();
	if (pid2 < 0)
		exitwitherror("PID ERROR");
	if (pid2 == 0)
	{
		int fdwritefile = open(argv[4], O_WRONLY, 0777);
		if (fdwritefile == -1)
			exitwitherror("Error while opening file");
		dup2(fd[0], STDIN_FILENO);
		dup2(fdwritefile, STDOUT_FILENO);
		close(fd[1]);
		execcmd(argv[3], env);
		close(fdwritefile);
	}

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return (0);
}