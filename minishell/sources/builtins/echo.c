/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:33:09 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/25 02:22:45 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	opt0(char **argv, int nwords, int i)
{
	ft_putstr_fd(argv[i], 1);
	if (i < (nwords - 1))
		ft_putchar_fd(32, 1);
}

void	opt1(char **argv, int nwords, int i)
{
	ft_putstr_fd(argv[i + 1], 1);
	if (i < (nwords - 2))
		ft_putchar_fd(32, 1);
}

/*!
 *	@function	echo
 *	@discussion	"echo text"		-> Prints text and ends with a newline.
 *				"echo -n text"	-> Prints text without newline.
 *	@param		argv	Single command.
 *	@param		opt		Equal to 0 without flag, 1 with flag.
 *	@return		0 if no error.
*/
size_t	echo(char **argv, int opt)
{
	int	i;
	int	nwords;

	i = 1;
	nwords = ft_2strlen(argv);
	if (((argv[1] == NULL) || ft_strlen(argv[1]) == 0) && \
	(ft_2strlen(argv) == 2))
	{
		ft_putchar_fd(10, 1);
		return (0);
	}
	while (i < nwords)
	{
		if (opt == 0)
			opt0(argv, nwords, i);
		else if (opt == 1)
			opt1(argv, nwords, i);
		i++;
	}
	if (opt == 0)
		ft_putchar_fd(10, 1);
	return (0);
}
