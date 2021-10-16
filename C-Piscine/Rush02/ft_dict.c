/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:08:10 by acrucesp          #+#    #+#             */
/*   Updated: 2020/12/13 20:53:05 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*ft_chrg(int fd, int sz)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc((sz + 1) * sizeof(char *));
	while (read(fd, &ptr[i], 1))
	{
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int		ft_sizef(int fd)
{
	int		num;
	char	*ptr;

	num = 0;
	while (read(fd, &ptr, 1))
		num++;
	return (num);
}

int		ft_openf(char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		write(1, "Dict Error\n", 11);
		return (-1);
	}
	else
		return (fd);
}

char	*ft_dict(char *file)
{
	int		fd;
	char	*buff;
	int		sz;

	fd = ft_openf(file);
	if (fd == -1)
		return (NULL);
	sz = ft_sizef(fd);
	close(fd);
	fd = ft_openf(file);
	buff = ft_chrg(fd, sz);
	close(fd);
	return (buff);
}
