/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:36:11 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/27 04:32:26 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	n_is_null(t_command **line, t_managervars *mvars)
{
	int	exitcode;

	exitcode = g_lastexit;
	close(mvars->fdout);
	ft_putstr_fd("exit\n", 2);
	free_all(mvars, line);
	exit(exitcode);
}

void	n_is_zero(t_command **line, t_managervars *mvars)
{
	close(mvars->fdout);
	ft_putstr_fd("exit\n", 2);
	free_all(mvars, line);
	exit(0);
}

void	n_is_empty(t_command **line, t_managervars *mvars)
{
	close(mvars->fdout);
	ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("minishell: exit: : numeric argument required\n", 2);
	free_all(mvars, line);
	exit(255);
}

void	n_is_not_a_number(t_command **line, t_managervars *mvars)
{
	close(mvars->fdout);
	ft_putstr_fd("exit\n", 2);
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(line[mvars->i]->argv[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	free_all(mvars, line);
	exit (255);
}

/*!
 *	@function	exit_bin
 *	@discussion	Exits minishell with exitcode if provided and valid. If exit
 *				argument is a string, it exits with code 255. If no argument
 *				is provided, minishell will exit with the exit code of the last
 *				executed command. Exits with code 0 otherwise.
 *	@param		line	Whole input string at prompt as an array of structs.
 *	@param		mvars	Pointer to struct containing variables used in manager.
*/
void	exit_builtin(t_command **line, t_managervars *mvars)
{
	int	exitcode;

	if (line[mvars->i]->argv[1] == NULL)
		n_is_null(line, mvars);
	else if (ft_strlen(line[mvars->i]->argv[1]) == 0)
		n_is_empty(line, mvars);
	else if (ft_strncmp(line[mvars->i]->argv[1], "0", \
	ft_strlen(line[mvars->i]->argv[1])) == 0)
		n_is_zero(line, mvars);
	else
	{
		exitcode = ft_atoi(line[mvars->i]->argv[1]);
		if (exitcode == 0)
			n_is_not_a_number(line, mvars);
		close(mvars->fdout);
		ft_putstr_fd("exit\n", 2);
		free_all(mvars, line);
		exit(exitcode);
	}
	exit(0);
}
