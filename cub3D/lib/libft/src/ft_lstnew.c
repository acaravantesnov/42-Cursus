/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:41:58 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/16 16:33:27 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newel;

	newel = malloc(sizeof(t_list));
	if (!newel)
		return (NULL);
	newel->content = content;
	newel->next = NULL;
	return (newel);
}
