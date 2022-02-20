/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:24:20 by acaravan          #+#    #+#             */
/*   Updated: 2022/02/19 21:58:43 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*void	mysleep(suseconds_t	time)
{
	struct timeval	t_inicial;
	struct timeval	t_actual;
	suseconds_t		dif;

	dif = 0;
	gettimeofday(&t_inicial, NULL);
	while (dif < time)
	{
		gettimeofday(&t_actual, NULL);
		dif = (t_actual.tv_sec - t_inicial.tv_sec) * 1000000;
		dif += (t_actual.tv_usec - t_inicial.tv_usec);
		usleep(500);
	}
}*/

suseconds_t	gettime(struct timeval time)
{
	suseconds_t	total;

	gettimeofday(&time, NULL);
	total = time.tv_sec * 1000000;
	total += time.tv_usec;
	return (total);
}

void	mysleep(suseconds_t time)
{
	struct	timeval	t_actual;
	suseconds_t		end_time;

	gettimeofday(&t_actual, NULL);
	end_time = (t_actual.tv_sec * 1000000) + t_actual.tv_usec + time;
	while (gettime(t_actual) < end_time)
		usleep(500);
}