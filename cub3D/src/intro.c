/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:40:27 by acaravan          #+#    #+#             */
/*   Updated: 2022/12/02 01:30:17 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*!
 *	@function	intro
 *	@abstract	Draws and prints into window a basic menu page for the program.
 *	@param		file	t_file struct containing all necessary data.
*/
void	intro(t_file *file)
{
	void	*backgr_img;
	void	*welcome1_img;
	void	*welcome2_img;
	int		img_width[3];
	int		img_height[3];

	backgr_img = mlx_xpm_file_to_image(file->mlx->mlx, \
	"textures/intro/intro.xpm", &(img_width[0]), &(img_height[0]));
	if (backgr_img != NULL)
		mlx_put_image_to_window(file->mlx->mlx, file->mlx->mlx_win, \
		backgr_img, 0, 0);
	welcome1_img = mlx_xpm_file_to_image(file->mlx->mlx, \
	"textures/intro/welcome1.xpm", &(img_width[1]), &(img_height[1]));
	if (welcome1_img != NULL)
		mlx_put_image_to_window(file->mlx->mlx, file->mlx->mlx_win, \
		welcome1_img, WIDTH / 2 - img_width[1] / 2, \
		HEIGHT / 2 - img_height[1] / 2);
	welcome2_img = mlx_xpm_file_to_image(file->mlx->mlx, \
	"textures/intro/welcome2.xpm", &(img_width[2]), &(img_height[2]));
	if (welcome2_img != NULL)
		mlx_put_image_to_window(file->mlx->mlx, file->mlx->mlx_win, \
		welcome2_img, WIDTH / 2 - img_width[2] / 2, \
		HEIGHT / 2 + img_height[2] / 2 + 40);
}
