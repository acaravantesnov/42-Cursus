/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_ptrs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:57:23 by airodrig          #+#    #+#             */
/*   Updated: 2022/11/26 14:11:37 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_double_chr_ptr(char **dbl_ptr)
{
	int	i;

	i = -1;
	while (dbl_ptr && dbl_ptr[++i])
		free(dbl_ptr[i]);
	if (dbl_ptr)
		free(dbl_ptr);
}

void	free_double_int_ptr(int **dbl_ptr)
{
	int	i;

	i = -1;
	while (dbl_ptr && dbl_ptr[++i])
		free(dbl_ptr[i]);
	if (dbl_ptr)
		free(dbl_ptr);
}
