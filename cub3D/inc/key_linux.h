/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_linux.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airodrig <airodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:40:13 by oouklich          #+#    #+#             */
/*   Updated: 2022/08/08 19:21:08 by airodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_LINUX_H
# define KEY_LINUX_H

/*
** Events
*/
# define KEYPRESS			2
# define KEYRELEASE			3
# define DESTROY_NOTIFY		17
# define ENTER_NOTIFY		7
# define BUTTON_PRESS		4
# define BUTTON_RELEASE		5

/*
** Keyboard LETTERS
*/

# define KEY_A 97
# define KEY_B 98
# define KEY_C 99
# define KEY_D 100
# define KEY_E 101
# define KEY_F 102
# define KEY_G 103
# define KEY_H 104
# define KEY_I 105
# define KEY_J 106
# define KEY_K 107
# define KEY_L 108
# define KEY_M 109
# define KEY_N 110
# define KEY_O 111
# define KEY_P 112
# define KEY_Q 113
# define KEY_R 114
# define KEY_S 115
# define KEY_T 116
# define KEY_U 117
# define KEY_V 118
# define KEY_W 119
# define KEY_X 120
# define KEY_Y 121
# define KEY_Z 122

/*
** Keyboard ARROWS
*/

# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364

/*
** Keyboard NUMPAD
*/

# define KEY_PAD_DIVIDE 65455
# define KEY_PAD_MULTIPLY 65450
# define KEY_PAD_SUB 65453
# define KEY_PAD_ADD 65451

/*
** Keyboard MISC
*/

# define KEY_SPACEBAR 32
# define KEY_ESCAPE 65307

/*
** Mouse
*/

# define M_CLK_L 1
# define M_CLK_R 3
# define M_CLK_M 2
# define M_SCR_U 4
# define M_SCR_D 5

#endif
