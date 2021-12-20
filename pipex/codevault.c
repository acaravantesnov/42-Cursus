/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codevault.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:06:28 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/19 17:27:28 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//pipe function

/*int	main(int argc, char *argv[])
{
	int fd[2];
	//fd[0] - read
	//fd[1] - write
	if (pipe(fd) == -1)
	{
		printf("An error occured with opening a pipe\n");
		return (1);
	}
	int id = fork();
	if (id == 0)
	{
		close(fd[0]);
		int x;
		printf("Input a number: "); scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("Got from child process: %d\n", y);
	}
	return (0);
}*/

//fork function

/*int main(int argc, char *argv[])
{
	int id = fork();
	//printf("Hello world from id: %d\n", id);
	if (id == 0)
	{
		printf("Hello for child process\n");
	}
	else
		printf("Hello from the main process\n");
	return (0);
}
*/

//wait function

/*int main(int argc, char *argv[])
{
	int id = fork();
	int n;
	if (id == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
	}
	for (int i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	return (0);
}*/



//dup and dup2

/*int	main(int argc, char *argv[])
{

}*/

//Simulating pipe operator

int	main(int argc, char *argv[])
{
	int fd[2];
	if (pipe(fd) == -1)
		return (1);

	int pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
	{
		// Child process 1 (ping)
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}

	int pid2 = fork();
	if (pid2 < 0)
		return (3);

	if (pid2 == 0)
	{
		// Child process 2 (grep)
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "round-trip", NULL);
	}

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return (0);
}
