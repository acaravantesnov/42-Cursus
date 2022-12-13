/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file_data_struct.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:55:57 by acaravan          #+#    #+#             */
/*   Updated: 2022/12/10 18:35:50 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*!
 *	@function	create_file_data_struct
 *	@discussion	Sets initial values for all variables in the t_file struct.
 *	@param		file	t_file struct containing all necessary data.
*/
void	create_file_data_struct(t_file *file)
{
	*file = (t_file){0, -1, (t_vector){0, 0}, (t_vector){0, 0}, NULL, 1, \
	NULL, NULL, (t_mlx *) malloc(sizeof(t_mlx)), (t_tex){0, 0, NULL}, \
	(t_tex){0, 0, NULL}, (t_tex){0, 0, NULL}, (t_tex){0, 0, NULL}, \
	INT32_MAX, INT32_MAX};
}
