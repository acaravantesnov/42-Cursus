/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 05:10:36 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/20 08:19:21 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(char *str);
int		*ft_realloc(int *ptr, int originSize, int newSize);
void	build_stacks(int *stackA, int *stackB, int ndigitsA);
void	sa(int *stackA, int ndigitsA);
void	sb(int *stackB, int ndigitsB);
void	ss(int *stackA, int *stackB, int ndigitsA, int ndigitsB);
void	pa(int *stackA, int *stackB, int ndigitsA, int ndigitsB);
void	pb(int *stackA, int *stackB, int ndigitsA, int ndigitsB);
void	ra(int *stackA, int ndigitsA);
void	rb(int *stackB, int ndigitsB);
void	rr(int *stackA, int *stackB, int ndigitsA, int ndigitsB);
void	rra(int *stackA, int ndigitsA);
void	rrb(int *stackB, int ndigitsB);
void	rrr(int *stackA, int *stackB, int ndigitsA, int ndigitsB);

#endif