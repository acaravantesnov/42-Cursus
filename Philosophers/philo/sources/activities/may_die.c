/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   may_die.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:16:28 by acaravan          #+#    #+#             */
/*   Updated: 2022/03/09 22:45:14 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	may_die1(suseconds_t *t_snc_sim_start, \
struct s_rules *rules, int *i)
{
	if (*(rules->sb_has_died) == 1)
		return (1);
	if ((*t_snc_sim_start > (rules->time_to_die * 1000)) && \
	(*t_snc_sim_start != 0))
	{
		printf("%d %d has died\n", \
		elapsed_time(rules, &(rules->sim_start), 0) / 1000, i[0] + 1);
		pthread_mutex_lock(rules->sb_has_died_mutex);
		*(rules->sb_has_died) = 1;
		pthread_mutex_unlock(rules->sb_has_died_mutex);
		return (1);
	}
	return (0);
}

int	may_die2(struct timeval *last_t_i_ate, suseconds_t *t_snc_last_t_i_ate, \
struct s_rules *rules, int *i)
{
	if (i[2] > 0)
	{
		*t_snc_last_t_i_ate = elapsed_time (rules, last_t_i_ate, 1);
		if ((*t_snc_last_t_i_ate > (rules->time_to_die * 1000)) && \
		(*t_snc_last_t_i_ate != 0))
		{
			printf("%d %d has died\n", \
			elapsed_time(rules, &(rules->sim_start), 0) / 1000, i[0] + 1);
			pthread_mutex_lock(rules->sb_has_died_mutex);
			*(rules->sb_has_died) = 1;
			pthread_mutex_unlock(rules->sb_has_died_mutex);
			return (1);
		}
		if (i[2] >= rules->number_of_times_each_philosopher_must_eat)
			return (1);
	}
	return (0);
}
