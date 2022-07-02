/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 01:35:27 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/30 18:27:40 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*!
 *	@function	manager
 *	@discussion	Manages fd's, seeks for builtins and forks a process
 *				for each binary to execute.
 *				It restores original fds, and checks if the last command has
 *				already ended. If so, it will kill all processes.
 *				It also stores the last exit value.
 *	@param		line	Whole input string at prompt as an array of structs.
 *	@param		envp	Environment variables.
*/
void	manager(t_command **line, char ***envp)
{
	t_managervars	*mvars;

	mvars = malloc(sizeof(t_managervars));
	setmvars(mvars, line);
	while (mvars->i < mvars->ncmds)
	{
		whilefct(mvars, line, envp);
		if (mvars->error == 1)
			break ;
		mvars->i++;
	}
	dup2(mvars->tempin, 0);
	dup2(mvars->tempout, 1);
	close(mvars->tempin);
	close(mvars->tempout);
	last_command_ended(mvars);
	while (mvars->wstatus > 255)
		mvars->wstatus -= 255;
	g_lastexit = mvars->wstatus;
	save_exceptions();
	while (wait(&(mvars->wstatus)) > 0)
		;
	free(mvars);
}
