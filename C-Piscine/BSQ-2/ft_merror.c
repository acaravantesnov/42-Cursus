/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:36:26 by manmarti          #+#    #+#             */
/*   Updated: 2020/12/15 18:32:50 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_merror.h"

char	*ft_chrg(int fs, int size)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!(ptr = (char *)malloc((size + 1) * sizeof(char))))
	{
		write(1, "Memory allocation error", 22);
		exit(-1);
	}
	while (read(fs, &ptr[i], 1))
	{
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int		ft_sizef(int fs)
{
	int		num;
	char	*ptr;

	num = 0;
	while (read(fs, &ptr, 1))
		num++;
	return (num);
}

int		ft_openf(char *file)
{
	int fs;

	if ((fs = open(file, O_RDONLY)) == -1)
	{
		write(1, "map error\n", 10);
		return (-1);
	}
	else
		return (fs);
}

int		**ft_merror(char *file, char *keys, int *dim)
{
	int		fs;
	char	*buff;
	int		size;

	fs = ft_openf(file);
	if (fs == -1)
		return (0);
	size = ft_sizef(fs);
	close(fs);
	fs = ft_openf(file);
	buff = ft_chrg(fs, size);
	close(fs);
	return (ft_gestmp(buff, keys, dim));
}
