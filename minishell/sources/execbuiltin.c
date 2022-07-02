/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execbuiltin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 04:20:24 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/27 04:31:34 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*!
 *	@function	execbuiltin
 *	@abstract	Executes the builtin found.
 *	@param		mvars	Pointer to struct containing variables used in manager.
 *	@param		line	Whole input string at prompt as an array of structs.
 *	@param		envp	Pointer to environment variables.
 *	@return		Exit code of builtins, -1 if error.
*/
size_t	execbuiltin(t_managervars *mvars, t_command **line, char ***envp)
{
	if (ft_strncmp(mvars->seekbinreturn, "echo", 7) == 0)
		return (echo(line[mvars->i]->argv, 0));
	else if (ft_strncmp(mvars->seekbinreturn, "echo -n", 7) == 0)
		return (echo(line[mvars->i]->argv, 1));
	else if (ft_strncmp(mvars->seekbinreturn, "cd", 2) == 0)
		return (cd(line[mvars->i]->argv[1], envp, mvars));
	else if (ft_strncmp(mvars->seekbinreturn, "pwd", 3) == 0)
		return (pwd());
	else if (ft_strncmp(mvars->seekbinreturn, "export", 6) == 0)
		return (export(line[mvars->i]->argv, envp));
	else if (ft_strncmp(mvars->seekbinreturn, "unset", 5) == 0)
		return (unset(line[mvars->i]->argv, envp));
	else if (ft_strncmp(mvars->seekbinreturn, "env", 3) == 0)
		return (env(envp));
	else if (ft_strncmp(mvars->seekbinreturn, "exit", 4) == 0)
		exit_builtin(line, mvars);
	return (-1);
}
