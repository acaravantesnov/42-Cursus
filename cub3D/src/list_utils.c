/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:16:09 by airodrig          #+#    #+#             */
/*   Updated: 2022/11/27 17:56:59 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*ft_newel(int place, int color, char *path)
{
	t_texture	*newel;

	newel = ft_calloc(1, sizeof(t_texture));
	if (!newel)
		return (NULL);
	newel->place = place;
	if (path)
		newel->path = ft_strdup(path);
	else
		newel->path = NULL;
	newel->color = color;
	newel->next = NULL;
	return (newel);
}

void	ft_lstaddback_check(t_texture **list, t_texture *newel)
{
	t_texture	*head;

	if (!*list)
		*list = newel;
	else
	{
		head = *list;
		while (head->next)
		{
			if (head->place == newel->place
				|| head->next->place == newel->place)
				print_error("A texture is repeated", false);
			head = head->next;
		}
		if (head->place == newel->place)
			print_error("A texture is repeated", false);
		head->next = newel;
	}
}
