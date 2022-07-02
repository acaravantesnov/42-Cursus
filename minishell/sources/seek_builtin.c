/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 04:18:52 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/25 02:17:01 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*!
 *	@function	seek_echo
 *	@param		argv	Single command.
 *	@return		String "echo" or "echo -n".
*/
char	*seek_echo(char **argv)
{
	size_t	i;

	if (argv[1] != NULL)
	{
		i = 1;
		while (i < ft_strlen(argv[1]))
		{
			if (argv[1][i] != 'n')
				break ;
			i++;
		}
		if ((ft_strncmp(argv[1], "-n", 2) == 0) && \
		(i == ft_strlen(argv[1])))
			return ("echo -n");
	}
	return ("echo");
}

/*!
 *	@function	seek_builtin
 *	@param		argv	Single command.
 *	@return		Name of builtin. NOT_FOUND otherwise.
*/
char	*seek_builtin(char **argv)
{
	if (ft_strncmp(argv[0], "echo", 5) == 0)
		return (seek_echo(argv));
	else if (ft_strncmp(argv[0], "cd", 3) == 0)
		return ("cd");
	else if (ft_strncmp(argv[0], "pwd", 4) == 0)
		return ("pwd");
	else if (ft_strncmp(argv[0], "export", 7) == 0)
		return ("export");
	else if (ft_strncmp(argv[0], "unset", 6) == 0)
		return ("unset");
	else if (ft_strncmp(argv[0], "env", 4) == 0)
		return ("env");
	else if (ft_strncmp(argv[0], "exit", 5) == 0)
		return ("exit");
	else
		return ("NOT_FOUND");
}
