/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 20:38:53 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/20 02:48:39 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook_1(int i, int exa)
{
	if (m.p_x != 1)
	{
		while ((i < g_n1) || (i < g_ncollec))
		{
			if ((one[i].x == m.p_x - 1) && (one[i].y == m.p_y))
				return (0);
			if ((collecc[i].x == m.p_x - 1) && (collecc[i].y == m.p_y))
				g_collected++;
			if ((E[0].x == m.p_x - 1) && (E[0].y == m.p_y) && (exa == 1))
				exit(0);
			if ((E[0].x == m.p_x - 1) && (E[0].y == m.p_y) && (exa != 1))
				return (0);
			i++;
		}
		g_nmov++;
		printf("Movements: %i\n", g_nmov);
		m.p_x--;
		caracterleft(&g_cleft, m.p_x, m.p_y);
	}
	return (0);
}

int	key_hook_2(int i, int exa)
{
	i = 0;
	if (m.p_x != m.x_size - 2)
	{
		while ((i < g_n1) || (i < g_ncollec))
		{
			if ((one[i].x == m.p_x + 1) && (one[i].y == m.p_y))
				return (0);
			if ((collecc[i].x == m.p_x + 1) && (collecc[i].y == m.p_y))
				g_collected++;
			if ((E[0].x == m.p_x + 1) && (E[0].y == m.p_y) && (exa == 1))
				exit(0);
			if ((E[0].x == m.p_x + 1) && (E[0].y == m.p_y) && (exa != 1))
				return (0);
			i++;
		}
		g_nmov++;
		printf("Movements: %i\n", g_nmov);
		m.p_x++;
		caracterright(&g_cright, m.p_x, m.p_y);
	}
	return (0);
}

int	key_hook_3(int i, int exa)
{
	i = 0;
	if (m.p_y != 1)
	{
		while ((i < g_n1) || (i < g_ncollec))
		{
			if ((one[i].x == m.p_x) && (one[i].y == m.p_y - 1))
				return (0);
			if ((collecc[i].x == m.p_x) && (collecc[i].y == m.p_y - 1))
				g_collected++;
			if ((E[0].x == m.p_x) && (E[0].y == m.p_y - 1) && (exa == 1))
				exit(0);
			if ((E[0].x == m.p_x) && (E[0].y == m.p_y - 1) && (exa != 1))
				return (0);
			i++;
		}
		g_nmov++;
		printf("Movements: %i\n", g_nmov);
		m.p_y--;
		caracterup(&g_cup, m.p_x, m.p_y);
	}
	return (0);
}

int	key_hook_4(int i, int exa)
{
	i = 0;
	if (m.p_y != m.y_size - 2)
	{
		while ((i < g_n1) || (i < g_ncollec))
		{
			if ((one[i].x == m.p_x) && (one[i].y == m.p_y + 1))
				return (0);
			if ((collecc[i].x == m.p_x) && (collecc[i].y == m.p_y + 1))
				g_collected++;
			if ((E[0].x == m.p_x) && (E[0].y == m.p_y + 1) && (exa == 1))
				exit(0);
			if ((E[0].x == m.p_x) && (E[0].y == m.p_y + 1) && (exa != 1))
				return (0);
			i++;
		}
		g_nmov++;
		printf("Movements: %i\n", g_nmov);
		m.p_y++;
		caracterdown(&g_cdown, m.p_x, m.p_y);
	}
	return (0);
}

/*
exa: exit available
*/
int	key_hook(int keycode)
{
	int	i;
	int	exa;

	i = 0;
	if (g_collected >= g_ncollec)
		exa = 1;
	else
		exa = 0;
	if (keycode == 53)
		exit(0);
	if (keycode == 0)
		key_hook_1(i, exa);
	if (keycode == 2)
		key_hook_2(i, exa);
	if (keycode == 13)
		key_hook_3(i, exa);
	if (keycode == 1)
		key_hook_4(i, exa);
	return (0);
}
