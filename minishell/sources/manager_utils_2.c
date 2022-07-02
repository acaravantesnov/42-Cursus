/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:54:45 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/30 18:06:23 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*!
 *	@function	setmvars
 *	@discussion	Saves original fds into tempin and tempout, and sets fdin
 *				depending if there is an infile.
 *	@param		mvars	Pointer to struct containing variables used in manager.
 *	@param		line	Whole input string at prompt as an array of structs.
*/
void	setmvars(t_managervars *mvars, t_command **line)
{
	mvars->pid_index = 0;
	mvars->wstatus = 0;
	mvars->tempin = dup(0);
	mvars->tempout = dup(1);
	if (line[0]->in_fd > 2)
		mvars->fdin = line[0]->in_fd;
	else
		mvars->fdin = dup(mvars->tempin);
	mvars->i = 0;
	mvars->ncmds = number_of_cmds(line);
}

/*!
 *	@function	setfds
 *	@discussion	For each command, it sets the appropiate fd values in order to
 *				redirect output depending whether a pipe or > is present.
 *	@param		mvars	Pointer to struct containing variables used in manager.
 *	@param		line	Whole input string at prompt as an array of structs.
*/
void	setfds(t_managervars *mvars, t_command **line)
{
	if (mvars->i == mvars->ncmds - 1)
		mvars->fdout = line[mvars->ncmds - 1]->out_fd * \
		(line[mvars->ncmds - 1]->out_fd > 2) + dup(mvars->tempout) * \
		!(line[mvars->ncmds - 1]->out_fd > 2);
	else if ((line[mvars->i]->out_fd > 2) || (line[mvars->i]->out_fd == -1))
	{
		pipe(mvars->fdpipe);
		close(mvars->fdpipe[1]);
		mvars->fdout = line[mvars->i]->out_fd;
	}
	else
	{
		pipe(mvars->fdpipe);
		mvars->fdout = mvars->fdpipe[1];
		mvars->fdin = mvars->fdpipe[0];
	}
	if ((mvars->i > 0) && ((line[mvars->i - 1]->out_fd > 2) || \
	(line[mvars->i - 1]->out_fd == -1) || (line[mvars->i - 1]->in_fd == -1)))
	{
		mvars->fdin = mvars->fdpipe[0];
		dup2(mvars->fdin, 0);
		close(mvars->fdin);
	}
}

/*!
 *	@function	last_command_ended
 *	@discussion	If the last command has ended, it kills all the processes.
 *				To do this, it has to access all the individual pid's stored in
 *				mvars struct.
 *	@param		mvars	Pointer to struct containing variables used in manager.
*/
void	last_command_ended(t_managervars *mvars)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	if (waitpid((mvars->pids)[mvars->pid_index - 1], &(mvars->wstatus), 0) > 0)
	{
		while (i < 1000000)
			i++;
		if (kill((mvars->pids)[mvars->pid_index - 1], SIGKILL))
			while (x < mvars->pid_index)
				kill((mvars->pids)[x++], SIGKILL);
	}
}

void	save_exceptions(void)
{
	if (g_lastexit == 2)
		g_lastexit = 130;
	else if (g_lastexit == 3)
		g_lastexit = 131;
}
