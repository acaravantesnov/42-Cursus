/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:33:54 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/25 03:36:38 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*!
 *	@function	pwd
 *	@abstract	Prints working directory.
 *	@return		0.
*/
size_t	pwd(void)
{
	char	cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		ft_putstr_fd("ups!\n", 2);
	else
	{
		ft_putstr_fd(cwd, 1);
		ft_putchar_fd(10, 1);
	}
	return (0);
}
