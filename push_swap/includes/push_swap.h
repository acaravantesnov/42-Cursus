/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 05:10:36 by acaravan          #+#    #+#             */
/*   Updated: 2021/12/28 19:20:16 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

long	ft_atoi(char *str);
int		ft_isdigit(int c);
int		ft_isnumber(char *num);
long	*ft_realloc(long *ptr, int originSize, int newSize);
int		check_params(int argc);
void	check_repeated_numbers(long *stackA, int ndigitsA);
void	check_numeric_limits(long *stackA, int ndigitsA);
void	parsing(long *stackA, int *ndigitsA, char **argv);
int		check_sorted(long *stackA, int *ndigitsA);
void	sort_3digits(long *sA, long *sB, int *ndigitsA);
void	sort_5digits(long *sA, long *sB, int *ndigitsA, int *ndigitsB);
void	sort_big_stack(long *sA, long *sB, int *ndigitsA, int *ndigitsB);
void	sa(long *stackA, int *ndigitsA);
void	sb(long *stackB, int *ndigitsB);
void	ss(long *stackA, long *stackB, int *ndigitsA, int *ndigitsB);
void	pa(long *stackA, long *stackB, int *ndigitsA, int *ndigitsB);
void	pb(long *stackA, long *stackB, int *ndigitsA, int *ndigitsB);
void	ra(long *stackA, int *ndigitsA);
void	rb(long *stackB, int *ndigitsB);
void	rr(long *stackA, long *stackB, int *ndigitsA, int *ndigitsB);
void	rra(long *stackA, int *ndigitsA);
void	rrb(long *stackB, int *ndigitsB);
void	rrr(long *stackA, long *stackB, int *ndigitsA, int *ndigitsB);

#endif