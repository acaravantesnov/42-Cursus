/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 19:03:31 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/14 19:12:28 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char *ptr;
	ptr = malloc(sizeof(char) * 4);
	int fd = open("example_file",O_RDONLY);
	int x = read(fd, ptr, 4);
	printf("%i",x);
	printf("%s",ptr);
	free(ptr);
	close(fd);
}