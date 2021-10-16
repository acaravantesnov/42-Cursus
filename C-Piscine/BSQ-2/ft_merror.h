/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merror.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:48:22 by manmarti          #+#    #+#             */
/*   Updated: 2020/12/15 20:25:06 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MERROR_H
# define FT_MERROR_H

int		**ft_gestmp(char *buff, char *keys, int *dim);
int		**ft_zerone(char **table, char *keys, int *dim);
int		count_wh(char *arr, int init, int *n);
int		count_h(char *arr, int init);

#endif
