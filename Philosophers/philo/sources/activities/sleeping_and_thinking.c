/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping_and_thinking.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:20:05 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/12 19:20:47 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	sleeping_and_thinking(struct s_rules *rules, int *i)
{
	if (i[1] == 2)
	{
		if (*(rules->sb_has_died) == 1)
			return (1);
		printf("%d %d is sleeping\n", \
		elapsed_time(rules, &(rules->sim_start), 0) / 1000, i[0] + 1);
		mysleep(rules->time_to_sleep * 1000);
		i[1] = 3;
	}
	if (i[1] == 3)
	{
		if (*(rules->sb_has_died) == 1)
			return (1);
		printf("%d %d is thinking\n", \
		elapsed_time(rules, &(rules->sim_start), 0) / 1000, i[0] + 1);
		i[1] = 0;
	}
	return (0);
}
