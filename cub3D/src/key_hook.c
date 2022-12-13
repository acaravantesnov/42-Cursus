/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:46:13 by acaravan          #+#    #+#             */
/*   Updated: 2022/12/07 20:32:18 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*!
 *	@function	key_hook
 *	@discussion	One of the most important functions in cub3D. It captures each
 *				key pressed and acts in consequence.
 *
 *				keycode == KEY_ESCAPE	->	EXIT
 *				keycode == KEY_A		->	ROTATE LEFT
 *				keycode == KEY_D		->	ROTATE RIGHT
 *				keycode == KEY_W		->	MOVE FRONT
 *				keycode == KEY_S		->	MOVE BACK
 *				keycode == KEY_LEFT		->	ROTATE 90º COUNTER CW
 *				keycode == KEY_RIGHT	->	ROTATE 90º CW
 *
 * 				It checks for collisions with walls, sets  and prints screen
 * 				img, casts rays, and draws everything (apart from intro).
 *
 *	@param		keycode	Code of the pressed key.
 *	@param		file	t_file struct containing all necessary data.
 *	@return		0.
*/
int	key_hook(int keycode, t_file *file)
{
	t_data	screen;
	double	olddirx;
	double	oldplanex;
	double	xy[2];

	set_screen(file, &screen);
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_A)
		rotate_left(file, &olddirx, &oldplanex);
	else if (keycode == KEY_D)
		rotate_right(file, &olddirx, &oldplanex);
	else if (keycode == KEY_W)
		move_forward(file, xy);
	else if (keycode == KEY_S)
		move_backward(file, xy);
	else if (keycode == KEY_RIGHT)
		rotate_90_ccw(file, &olddirx, &oldplanex);
	else if (keycode == KEY_LEFT)
		rotate_90_cw(file, &olddirx, &oldplanex);
	cast_rays(file);
	draw(file, &screen);
	mlx_put_image_to_window(file->mlx->mlx, file->mlx->mlx_win, \
	screen.img, 0, 0);
	return (0);
}
