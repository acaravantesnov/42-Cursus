/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:38:15 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/30 18:33:11 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*!
 *	@function	command_not_found
 *	@abstract	Prints error message. It also sets exit value to 127.
 *	@param		mvars	Pointer to struct containing variables used in manager.
 *	@param		line	Whole input string at prompt as an array of structs.
*/
void	command_not_found(t_managervars *mvars, t_command **line)
{
	close(mvars->fdout);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(line[mvars->i]->argv[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	mvars->wstatus = 127;
	mvars->error = 1;
}

/*!
 *	@function	not_builtin
 *	@discussion	Checks if the first agument of each single command is a builtin.
 *				If no valid command is found, it calls function
 *				command_not_found.
 *	@param		mvars	Pointer to struct containing variables used in manager.
 *	@param		line	Whole input string at prompt as an array of structs.
 *	@param		envp	Environment variables.
 *	@param		aux		Auxiliary string.
*/
void	not_builtin(t_managervars *mvars, t_command **line, char ***envp, \
char *aux)
{
	aux = find_path(line[mvars->i]->argv[0], *envp);
	if (((aux == NULL) && \
	(access(aux, X_OK) == -1)) || \
	(ft_2strlen(line[mvars->i]->argv) == 0))
		command_not_found(mvars, line);
	else if ((aux != NULL) && (access(aux, X_OK) == -1))
		command_not_found(mvars, line);
	if ((line[mvars->i]->argv[0][0] != '/') && \
	(ft_strncmp(line[mvars->i]->argv[0], "./", 2) != 0))
		free(aux);
}

void	command_exists(t_managervars *mvars, t_command **line, char ***envp, \
char *aux)
{
	if ((line[mvars->i]->out_fd == -1) || \
	(line[mvars->i]->out_fd == -1))
		close(STDOUT_FILENO);
	else
	{
		dup2(mvars->fdout, STDOUT_FILENO);
		close(mvars->fdout);
	}
	ft_strcpy(mvars->seekbinreturn, seek_builtin(line[mvars->i]->argv));
	if (ft_strncmp(mvars->seekbinreturn, "NOT_FOUND", 9) == 0)
		not_builtin(mvars, line, envp, aux);
	else if (ft_strncmp(mvars->seekbinreturn, "NOT_FOUND", 9) != 0)
		mvars->wstatus = execbuiltin(mvars, line, envp);
	if ((ft_strncmp(mvars->seekbinreturn, "NOT_FOUND", 9) == 0) && \
	(mvars->error != 1))
		process(line, mvars, *envp);
}

/*!
 *	@function	whilefct
 *	@discussion	Iterates over each single command,
 *				redirects output, and executes binary or builtin.
 *				When executing a builtin, it stores its return value in
 *				g_lastexit.
 *	@param		mvars	Pointer to struct containing variables used in manager.
 *	@param		line	Whole input string at prompt as an array of structs.
 *	@param		envp	Environment variables.
*/
void	whilefct(t_managervars *mvars, t_command **line, char ***envp)
{
	char	*aux;

	aux = NULL;
	mvars->seekbinreturn = malloc (8 * sizeof(char));
	mvars->error = 0;
	if (line[mvars->i]->in_fd != -1)
	{
		dup2 (mvars->fdin, STDIN_FILENO);
		close (mvars->fdin);
		setfds(mvars, line);
		if ((ft_2strlen(line[mvars->i]->argv) == 0) || \
		(ft_strlen(line[mvars->i]->argv[0]) == 0))
			command_not_found(mvars, line);
		else
			command_exists(mvars, line, envp, aux);
		free(mvars->seekbinreturn);
	}
	else
	{
		close(STDIN_FILENO);
		free(mvars->seekbinreturn);
	}
}
