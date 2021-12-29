/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 08:21:18 by prranges          #+#    #+#             */
/*   Updated: 2021/11/10 08:21:27 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(int id)
{
	g_data.i = id;
	g_data.dead_philo = 0;
	while (g_data.i < g_data.number_of_philosophers)
	{
		if (pthread_create(&g_data.t[g_data.i], NULL, \
						   routine, &g_data.philo[g_data.i]))
			return (ERR);
		g_data.philo[g_data.i].start_time = current_time();
		g_data.i++;
		g_data.i++;
		usleep(333);
	}
	return (OK);
}

void	join_threads(void)
{
	g_data.i = -1;
	while (++g_data.i < g_data.number_of_philosophers)
		pthread_join(g_data.t[g_data.i], NULL);
	printf("Every philosopher ate %d times\n", g_data.number_of_times_must_eat);
}

void	detach_threads(int i)
{
	g_data.i = -1;
	while (++g_data.i < g_data.number_of_philosophers)
		pthread_detach(g_data.t[g_data.i]);
	pthread_mutex_lock(&g_data.mutex_print);
	printf("%ld %d is died\n", current_time(), g_data.philo[i].id);
	printf("Philosopher %d ", g_data.philo[i].id);
	printf("starved for %ld ms\n", g_data.starving);
}
