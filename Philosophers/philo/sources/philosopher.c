/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:26:38 by acaravan          #+#    #+#             */
/*   Updated: 2022/03/09 22:15:12 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
**	i[0] -> n
**	i[1] -> activity
**	i[2] -> has_eaten
**
**	activity == 0 -> Waiting to eat
**	activity == 1 -> Eating
**	activity == 2 -> Sleeping
**	activity == 3 -> Thinking
**
**	times[0] -> t_snc_sim_start
**	times[1] -> t_snc_last_t_i_ate
*/

void	initial_sleep(int *i, struct s_rules *rules)
{
	if (i[0] % 2 != 0)
		mysleep(1000, rules);
}

void	*philosopher(void *arg)
{
	int				i[3];
	struct s_rules	*rules;
	struct timeval	last_t_i_ate;
	suseconds_t		times[2];

	rules = arg;
	i[0] = *(rules->iter);
	i[1] = 0;
	i[2] = 0;
	times[0] = elapsed_time(rules, &(rules->sim_start), 0);
	times[1] = 0;
	initial_sleep(i, rules);
	while (1)
	{
		if ((may_die1(&(times[0]), rules, i) == 1) || \
		(may_die2(&(last_t_i_ate), &(times[1]), rules, i) == 1))
			return (NULL);
		if (waiting_to_eat(rules, i) == 1)
			return (NULL);
		if (eating(&(last_t_i_ate), &(times[0]), rules, i) == 1)
			return (NULL);
		if (sleeping_and_thinking(rules, i) == 1)
			return (NULL);
	}
	return (NULL);
}
