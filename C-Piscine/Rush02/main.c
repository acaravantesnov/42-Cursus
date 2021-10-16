/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 12:13:42 by manmarti          #+#    #+#             */
/*   Updated: 2020/12/13 22:09:32 by juanmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		i;
	char	**str;
	char	*a;

	a = 0;
	if ((i = ft_gerror(argv, argc)))
	{
		str = ft_slicer(argv[i]);
		if (argc == 3)
			a = ft_dict(argv[1]);
		else if (argc == 2)
			a = ft_dict("numbers.dict");
		if (a == NULL)
			return (0);
		ft_cooldict(a);
		free(str);
	}
	return (0);
}
