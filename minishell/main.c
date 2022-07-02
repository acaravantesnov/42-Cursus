/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 22:37:33 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/30 18:36:05 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

/*!
 *	@function	main
 *	@discussion	Creates a copy for envp, sets SIGINT and SIGQUIT signals and
 *				creates a loop to go through the prompt.
 *	@param		argc	Number of arguments.
 *	@param		argv	Arguments.
  *	@param		envp	Environment variables.
*/
int	main(int argc, char **argv, char **envp)
{
	char		**envpcpy;
	t_command	**line;

	(void)argc;
	g_lastexit = 0;
	envpcpy = ft_envp_copy(&envp);
	signal(SIGINT, &sighandler);
	signal(SIGQUIT, &sighandler);
	while (1)
	{
		line = (t_command **)malloc(sizeof(t_command *));
		line[0] = NULL;
		parse_line(&envpcpy, argv, &line);
		free_middle(line);
	}
	free_2pointer(envpcpy);
	return (0);
}
