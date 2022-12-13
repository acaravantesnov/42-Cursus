/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:25:18 by acaravan          #+#    #+#             */
/*   Updated: 2022/12/10 20:06:16 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*!
 *	@function	special_cpy
 *	@abstract	Same behaviour as ft_strlcpy, just adapted for int arrays.
 *	@param		dst		Pointer to destination.
 *	@param		src		Pointer to source.
 *	@param		size	Size of elements to be copied from src into dst.
 *	@return		Number of copied integer values.
*/

void	special_cpy(t_tex *dst, int *data_addr, t_data data)
{
	size_t			cnt;
	const size_t	size = data.img_width * data.img_height;

	cnt = 0;
	dst->width = data.img_width;
	dst->height = data.img_height;
	dst->addr = (int *)malloc(sizeof(int) * size);
	if (!size)
		return ;
	while (data_addr[cnt] && (cnt < size - 1))
	{
		(dst->addr)[cnt] = data_addr[cnt];
		cnt++;
	}
	return ;
}

/*!
 *	@function	prepare_textures
 *	@discussion	Iterates through all saved textures in file->textures, sets
 *				them, and saves their addr into file->N, file->S, file->E and
 *				file->W.
 *	@param		file	t_file struct containing all necessary data.
*/
void	prepare_textures(t_file *file)
{
	t_texture	*aux;

	aux = file->textures;
	while (aux != NULL)
	{
		if (aux->path != NULL)
			aux->data.img = mlx_xpm_file_to_image(file->mlx->mlx, \
			aux->path, &(aux->data.img_width), &(aux->data.img_height));
		if (aux->data.img != NULL)
			aux->data.addr = mlx_get_data_addr(aux->data.img, \
			&(aux->data.bits_per_pixel), &(aux->data.line_length), \
			&(aux->data.endian));
		if (aux->path && (aux->data.img_width < 64 \
			|| aux->data.img_height < 64))
			print_error("Texture too small. Minimum size: 64x64", false);
		if (aux->place == 0)
			special_cpy(&(file->n), (int *)aux->data.addr, aux->data);
		else if (aux->place == 1)
			special_cpy(&(file->s), (int *)aux->data.addr, aux->data);
		else if (aux->place == 2)
			special_cpy(&(file->e), (int *)aux->data.addr, aux->data);
		else if (aux->place == 3)
			special_cpy(&(file->w), (int *)aux->data.addr, aux->data);
		aux = aux->next;
	}
}
