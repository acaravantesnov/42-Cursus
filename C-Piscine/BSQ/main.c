/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:10:40 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/14 21:58:13 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*int error(char *str)
{
	int i;
	if ((str[0] == '-') || (str[0] < 48) || (str[0] > 57) )
		return (1);
	i = 0;
	while(i < 3)
	{
		if (str[ft_strlen(str) - i])
			
		i++;
	}
	else
		return (0);
}*/

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	int i;
	int j;
	char *primera;

	primera = malloc((sizeof (char)) * 4);

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) 
		write(1, "Error", 5);
	else
	{
		int x = read(fd, primera, 4);
		printf("%s", primera);
    

		int y;
		y = primera[0] - 48;

		char **ml;
	    ml = malloc(sizeof(char *) * y);
	    while(i < y)
	    {
	        ml[i] = malloc(sizeof(char *) * y);
	        i++;
	    }

		/*while(i < x)
		{
			int x = read(fd, &ml[i], )
		}*/
		/*char v;
		char o;
		char l;*/

	
	}
	return (0);
}