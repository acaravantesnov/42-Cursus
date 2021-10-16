/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:25:29 by acaravan          #+#    #+#             */
/*   Updated: 2020/12/09 18:38:39 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int        nbase(char *base)
{
    int basse;
    int i;

    basse = 0;
    i = 0;
    while (base[i] != '\0')
    {
        if ((base[i] == '+') || (base[i] == '-'))
            return (0);
        basse++;
        i++;
    }
    if ((basse == 1) || (basse == 0))
        return (0);
    return (basse);
}

int        ndigits(int nbr)
{
    int i;
    int digits;

    i = 0;
    digits = 0;
    while (nbr > 1)
    {
        nbr /= 10;
        digits++;
    }
    return (digits);
}

char    *ntoc(int nbr, int size, char *numberinc)
{
    int i;

    i = size;
    while(i > 0)
    {
        if(i == size)
            numberinc[i] = (nbr % 10) + 48;
        else
        {
            numberinc[i] = (nbr / (10 * (size - i)) + 48);
        }
        i--;
    }
    return (numberinc);
}

void    ft_putnbr_base(int nbr, char *base)
{
    if(nbase(base) != 0)
    {
        int i;
        int total;
        char numberinc[ndigits(nbr)];

		i = 0;
		while(i < ndigits(nbr))
		{
			numberinc[i] = 0;
			i++;
		}

        printf("Digitos: %i\nBase: %i\n",ndigits(nbr),nbase(base));
        printf("%s", ntoc(nbr,ndigits(nbr),numberinc));
    }
}

int main(){
    ft_putnbr_base(232323,"0123456789");
}