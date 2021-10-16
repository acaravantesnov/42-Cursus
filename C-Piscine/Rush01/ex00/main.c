/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 12:09:22 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/06 19:37:40 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int hayalgo(int x, int y, int **ml);

void ft_putchar(char c)
{
	write(1, &c, 1);
}

char *delete_spaces(char *input_string)
{
	static char a[17];
	unsigned int i;
	unsigned int j;

	//a[16] = '\0';
	i = 0;
	j = 0;
	while(i < 32)
	{
		if (i % 2 == 0)
		{
			a[j] = input_string[i];
			j++;
		}
		i++;
	}
	return (a);
}

void print_error(void)
{
	int a;

	a = 0;
	char *error = "Error";
	while (a < 5)
	{
		ft_putchar(error[a]);
		a++;
	}
	ft_putchar(012);
}

int valid_row_column(char *clue)
{
	int a;
	int one_counter;
	int two_counter;
	int three_counter;
	int four_counter;
	
	a = 0;
	one_counter = 0;
	two_counter = 0;
	three_counter = 0;
	four_counter = 0;
	while (a < 4)
	{
		if(!(clue[a] >= '1' && clue[a] <= '4'))
			return (1);
		if(clue[a] == '4')
			four_counter++;
		if(clue[a] == '1')
			one_counter++;
		if(clue[a] == '2')
			two_counter++;
		if(clue[a] == '3')
			three_counter++;
		a++;
	}
	if (one_counter > 1 || two_counter > 3 || three_counter > 2 || four_counter > 1)
		return (1);
	else
		return (0);
}

int	is_solvable(char *colup, char *coldown, char *rowleft, char *rowright)
{
	int a;
	int valid_colup;
	int valid_coldown;
	int valid_rowleft;
	int valid_rowright;

	a = 0;
	while (a < 4)
	{
		if (!(((colup[a] + coldown[a]) - 48 >= '3') && ((colup[a] + coldown[a]) - 48 <= '5')))
			return (1);
		if (!(((rowleft[a] + rowright[a]) - 48 >= '3') && ((rowleft[a] + rowright[a]) - 48 <= '5')))
			return (1);
		a++;
	}
	valid_colup = valid_row_column(colup);
	valid_coldown = valid_row_column(coldown);
	valid_rowleft = valid_row_column(rowleft);
	valid_rowright = valid_row_column(rowright);
	if (valid_colup == 1 || valid_coldown == 1 || valid_rowleft == 1 || valid_rowright == 1)
		return (1);
	else
		return (0);
}

int        main(int argc, char **argv)
{
    argc = 1;
    //char argv[] = "2 1 2 3 1 2 3 2 2 2 4 1 2 2 1 4";
    char a[17];
    int b[16];
    int i;
    int j;
    unsigned int k;
    unsigned int l;
    
    i = 0;
    int **ml;
    ml = malloc(sizeof(int *) * 4);
    while(i < 4)
    {
        ml[i] = malloc(sizeof(int *) * 4);
        i++;
    }

    i = 0;
    j = 0;
    //a[16] = '\0';
    //while (argv[i] != '\0')
    while (i < 32)
    {
        if((i % 2) == 0)
        {
            a[j] = argv[1][i];
            j++;
        }
        i++;
    }
    i = 0;
    while(i<16)
    {
        b[i] = a[i] - 48;
        i++;
    }
    int colup[4];
    int coldown[4];
    int rowleft[4];
    int rowright[4];

    char colupc[4];
    char coldownc[4];
    char rowleftc[4];
    char rowrightc[4];

    i = 0;
    j = 0;
    k = 0;
    l = 0;
    
    //while (a[i] != '\0')
    while (i < 16)
    {
        if (i < 4)
        {
            colup[i] = b[i];
            colupc[i] = a[i];
        }
        else if ((i >= 4) && (i < 8))
        {
            coldown[j] = b[i];
            coldownc[j] = a[i];
            j++;
        }
        else if ((i >= 8) && (i < 12))
        {
            rowleft[k] = b[i];
            rowleftc[k] = a[i];
            k++;
        }
        else if ((i >= 12) && (i < 16))
        {
            rowright[l] = b[i];
            rowrightc[l] = a[i];
            l++;
        }
        i++;
    }

    //printf("%s", colupc);

    //Comprobacion

    int error_pass;
	error_pass = is_solvable(colupc, coldownc, rowleftc, rowrightc);
	if (error_pass == 1)
	   print_error();
	else{
        //Crear vacia
        
        i = 0;
        j = 0;
        while(i < 4)
        {
            j = 0;
            while(j < 4)
            {
                ml[i][j] = 0;
                j++;
            }
            i++;
        }
        

        //Rellenar
        i = 0;
        while(i < 4)
        {
            if(colup[i] == 4)
            {
                j = 0;
                while(j < 4)
                {
                    if (hayalgo(j,i,ml) == 0)
                        {
                            ml[j][i] = j + 1;
                        }
                    j++;
                }
            }
            else if(colup[i] == 1)
            {
                ml[0][i] = 4;
            }
            i++;
        }
        
        i = 0;
        while(i < 4)
        {
            if(coldown[i] == 4)
            {
                j = 4;
                while(j >= 0)
                {
                    if (hayalgo(j,i,ml) == 0)
                    {
                        ml[j][i] = 4 - j;
                    }
                    j--;
                }
            }
            else if(coldown[i] == 1)
            {
                ml[3][i] = 4;
            }
            i++;
        }
        
        i = 0;
        while(i < 4)
        {
            if(rowleft[i] == 4)
            {
                j = 0;
                while(j < 4)
                {
                    if (hayalgo(i, j, ml) == 0)
                    {
                        ml[i][j] = j + 1;
                    }
                    j++;
                }
            }
            else if(rowleft[i] == 1)
            {
                ml[i][0] = 4;
            }
        i++;
        }
        
        i = 0;
        while(i < 4)
        {
        if(rowright[i] == 4)
        {
            j = 3;
            while(j >= 0)
            {
                if (hayalgo(i, j, ml) == 0)
                {
                    ml[i][j] = 4 - j;
                }
                j--;
            }
        }
        else if(rowright[i] == 1)
        {
            ml[i][3] = 4;
        }
        i++;
        }
    //PintarMatriz
        i = 0;
        j = 0;
        while(i < 4)
        {
            j = 0;
            while (j < 4)
            {
            char r;
            r = ml[i][j] + 48;
            write(1, &r, 1);
            j++;
            }
            write(1, "\n", 1);
            i++;
        }
        }
}

int hayalgo(int x, int y, int **ml)
{
  if(ml[x][y] == 0)
  {
    return (0);
  }
  else
  {
    return (1);
  }
  return (0);
}