/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:24:32 by manmarti          #+#    #+#             */
/*   Updated: 2020/12/15 16:36:26 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int main(int argc, char **argv)
{
    int i;
    int dim[3];
    char keys[3];
    int **table;

    i = 1;
    if (argc == 1)
    {

        
    }
    else if (argc > 1)
    {
        while (i < argc)
        {
            if ((table = ft_merror(argv[i], keys, dim)))
            i++;
        }
    }
    return (0);
}