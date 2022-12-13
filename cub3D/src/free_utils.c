/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:05:08 by airodrig          #+#    #+#             */
/*   Updated: 2022/12/10 17:39:58 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_textures(t_texture **lst)
{
	t_texture	*head;

	while (*lst)
	{
		head = (*lst)->next;
		free((*lst)->path);
		free(*lst);
		*lst = head;
	}
}

/*!
 *	@function	free_file
 *	@abstract	Frees all allocated memory. It is called when pressing ESC.
 *	@param		lst	t_file struct containing all necessary data.
*/
void	free_file(t_file *lst)
{
	if (lst->textures)
		free_textures(&(lst->textures));
	if (lst->map)
		free_double_chr_ptr(lst->map);
	if (lst->buffer)
		free_double_int_ptr(lst->buffer);
	free(lst->mlx->player);
	free(lst->mlx);
	free(lst->n.addr);
	free(lst->s.addr);
	free(lst->e.addr);
	free(lst->w.addr);
	free(lst);
}
