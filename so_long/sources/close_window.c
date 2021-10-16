/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 05:07:54 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/17 23:08:09 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(int keycode)
{
	keycode++;
	mlx_destroy_window(mlx.mlx, mlx.mlx_win);
	exit (0);
}
