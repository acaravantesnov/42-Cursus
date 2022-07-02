/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_cmds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 02:45:33 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/24 19:08:01 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*!
 *	@function	number_of_cmds
 *	@abstract	Equivalent to ft_strlen but for t_command **line.
 *	@param		line	Whole input string at prompt as an array of structs.
 *	@return		Number of commands.
*/
size_t	number_of_cmds(t_command **line)
{
	size_t	i;

	i = 0;
	while (line[i] != NULL)
		i++;
	return (i);
}
