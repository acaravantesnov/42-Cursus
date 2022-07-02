/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:04:38 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/30 18:29:56 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*!
 *	@function	process
 *	@discussion	For each binary, it creates a new process, saves its pid, and
 *				executes its path.
 *	@param		line	Whole input string at prompt as an array of structs.
 *	@param		mvars	Pointer to struct containing variables used in manager.
 *	@param		envp	Environment variables.
*/
void	process(t_command **line, t_managervars *mvars, char **envp)
{
	pid_t	pid;

	pid = fork();
	mvars->pids[mvars->pid_index++] = pid;
	if (pid == 0)
	{
		mvars->path = find_path(line[mvars->i]->argv[0], envp);
		execve(mvars->path, line[mvars->i]->argv, envp);
	}
	else if (pid < 0)
	{
		close(mvars->fdout);
		perror ("fork");
		exit(1);
	}
}
