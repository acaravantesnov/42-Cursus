/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:42:48 by airodrig          #+#    #+#             */
/*   Updated: 2022/12/10 20:55:10 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	leaks(void)
{
	system("leaks cub3D");
}

/*!
 *	@function	main
 *	@discussion	Creates t_file data structure, checks input and the parses map.
 *				It also calculates tile size in px, creates a new window and
 *				determines initial position and direction of player in the map.
 *				Then, it draws an intro menu in screen and loops waiting for
 *				user input in the form of key pressing.
 *				It finally frees allocated memory to avoid leaks and returns 0.
 *	@param		argc	Number of arguments.
 *	@param		argv	Arguments.
 *	@return		0 if no error is found, errno otherwise.
*/
int	main(int argc, char const *argv[])
{
	int		map_fd;
	t_file	*file;
	int		save_ij[2];

	initial_input_checking(argc, argv, &map_fd);
	file = (t_file *)malloc(sizeof(t_file));
	create_file_data_struct(file);
	file->mlx->mlx = mlx_init();
	parse_file(map_fd, file);
	build_buffer(file);
	prepare_textures(file);
	file->tile_size = calc_tile_size(file);
	file->mlx->mlx_win = \
	mlx_new_window(file->mlx->mlx, WIDTH, HEIGHT, "./cub3D");
	find_player(file, 0, 0, save_ij);
	intro(file);
	mlx_hook(file->mlx->mlx_win, KEYPRESS, 0, key_hook, file);
	mlx_hook(file->mlx->mlx_win, DESTROY_NOTIFY, 0, close_window, file);
	mlx_loop(file->mlx->mlx);
	return (0);
}
