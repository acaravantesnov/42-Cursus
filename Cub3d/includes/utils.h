/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:45:55 by acaravan          #+#    #+#             */
/*   Updated: 2022/08/02 00:54:18 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "../mlx/mlx.h"

# define	WIDTH 	2060
# define	HEIGHT	1220

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_player
{
	float px;
	float py;
}	t_player;

typedef struct	s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_player	*player;
}	t_mlx;
#endif