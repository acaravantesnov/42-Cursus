/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 17:20:53 by acaravan          #+#    #+#             */
/*   Updated: 2021/08/30 17:24:55 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*actualnode;

	actualnode = malloc(sizeof(t_list));
	if (actualnode == NULL)
		return (NULL);
	actualnode->content = content;
	actualnode->next = NULL;
	return (actualnode);
}
