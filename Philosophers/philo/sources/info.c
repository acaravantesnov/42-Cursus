/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:09:54 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/03 14:18:27 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	info(struct s_rules *rules)
{
	printf("Forks: ");
	for (int x = 0; x < rules->number_of_philosophers; x++)
		printf("%d ", rules->forks[x]);	
	printf("\nHands: \n");
	for (int x = 0; x < rules->number_of_philosophers; x++)
		printf("%d %d\n", rules->manos[x][0], rules->manos[x][1]);
}
