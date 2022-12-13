/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:28:14 by acaravan          #+#    #+#             */
/*   Updated: 2022/12/02 01:19:06 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*!
 *	@function	close_window
 *	@abstract	Closes window when red cross is clicked. Exits with exit code 0.
 *	@param		keycode	Casted to void.
 *	@param		file	Casted to void.
 *	@return		0.
*/
int	close_window(int keycode, t_file *file)
{
	(void)keycode;
	(void)file;
	exit (0);
}
