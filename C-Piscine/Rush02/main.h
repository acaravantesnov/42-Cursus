/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:57:12 by manmarti          #+#    #+#             */
/*   Updated: 2020/12/13 20:54:26 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

int		ft_gerror(char **argv, int argc);
char	**ft_slicer(char *argv);
char	*ft_dict(char *file);
char	**ft_cooldict(char *dict);

#endif
