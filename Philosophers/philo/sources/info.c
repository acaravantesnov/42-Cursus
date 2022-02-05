/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:09:54 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/05 16:15:33 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	info(struct s_rules *rules)
{
	printf("Forks: ");
	for (int x = 0; x < rules->number_of_philosophers; x++)
		printf("%d ", rules->forks[x]);
}
