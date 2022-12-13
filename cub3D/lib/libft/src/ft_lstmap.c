/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:36:21 by airodrig          #+#    #+#             */
/*   Updated: 2021/09/18 16:18:32 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;

	if (!lst || !f)
		return (NULL);
	aux = ft_lstnew((*f)(lst->content));
	if (!aux)
		return (NULL);
	new = aux;
	lst = lst->next;
	while (lst)
	{
		aux->next = ft_lstnew((*f)(lst->content));
		if (!(aux->next))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		lst = lst->next;
		aux = aux->next;
	}
	aux->next = NULL;
	return (new);
}
