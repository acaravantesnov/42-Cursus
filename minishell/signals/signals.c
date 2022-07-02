/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:36:04 by acaravan          #+#    #+#             */
/*   Updated: 2022/06/30 16:20:43 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*!
 *	@function	sighandler
 *	@discussion	Checks whether the signal captured is Ctrl-C (SIGINT), or Ctrl-\
 *				(SIGQUIT).
 *	@param		signum	Integer value of the signal that has been captured.
 *	@return		Name of builtin. NOT_FOUND otherwise.
*/
void	sighandler(int signum)
{
	if (signum == SIGINT)
	{
		g_lastexit = 1;
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		return ;
	}
	else if (signum == SIGQUIT)
	{
		write(1, "\33[2K", 4);
		rl_on_new_line();
		rl_redisplay();
		return ;
	}
}
