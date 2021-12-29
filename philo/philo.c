/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:37:47 by prranges          #+#    #+#             */
/*   Updated: 2021/10/11 13:37:53 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitoring(void)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < g_data.number_of_philosophers)
		{
			if (g_data.philo[i].last_eat_time == 0)
				g_data.philo[i].last_eat_time = g_data.philo[i].start_time;
			g_data.starving = current_time() - g_data.philo[i].last_eat_time;
			if (g_data.current_times_of_eat == g_data.number_of_times_must_eat)
				return (END);
			else if (g_data.starving > g_data.time_to_die)
			{
				g_data.dead_philo = i;
				return (DEAD);
			}
		}
		usleep(999);
	}
	return (OK);
}

void	*routine(void *arg)
{
	t_philo	*p;
	int		limit_of_meals;

	p = (t_philo *)arg;
	limit_of_meals = g_data.number_of_times_must_eat;
	while (limit_of_meals)
	{
		pthread_mutex_lock(p->right_fork);
		print_status(p->id, TAKE_FORK);
		pthread_mutex_lock(p->left_fork);
		print_status(p->id, TAKE_FORK);
		print_status(p->id, EATING);
		p->last_eat_time = current_time();
		my_sleep(g_data.time_to_eat);
		print_status(p->id, SLEEPING);
		pthread_mutex_unlock(p->left_fork);
		pthread_mutex_unlock(p->right_fork);
		my_sleep(g_data.time_to_sleep);
		print_status(p->id, THINKING);
		if (limit_of_meals != LOOP)
			limit_of_meals--;
	}
	g_data.current_times_of_eat = g_data.number_of_times_must_eat;
	return (OK);
}

int	init_philosophers(void)
{
	g_data.i = 0;
	while (g_data.i < g_data.number_of_philosophers)
	{
		g_data.philo[g_data.i].last_eat_time = 0;
		g_data.philo[g_data.i].id = g_data.i + 1;
		if (pthread_mutex_init(&g_data.philo[g_data.i].fork, NULL))
			return (ERR);
		g_data.philo[g_data.i].right_fork = &g_data.philo[g_data.i].fork;
		if (g_data.i == (g_data.number_of_philosophers - 1))
			g_data.philo[g_data.i].left_fork = &g_data.philo[0].fork;
		else
			g_data.philo[g_data.i].left_fork = &g_data.philo[g_data.i + 1].fork;
		g_data.i++;
	}
	if (pthread_mutex_init(&g_data.mutex_print, NULL))
		return (ERR);
	return (OK);
}

int	start_philosohpers(void)
{
	int	result;

	g_data.philo = malloc(sizeof(t_philo) * g_data.number_of_philosophers);
	if (!g_data.philo)
		return (M_ERR);
	g_data.t = malloc(sizeof(pthread_t) * g_data.number_of_philosophers);
	if (!g_data.t)
		return (M_ERR);
	init_philosophers();
	create_threads(1);
	usleep(777);
	create_threads(0);
	result = monitoring();
	if (result == END)
		join_threads();
	else if (result == DEAD)
		detach_threads(g_data.dead_philo);
	return (result);
}

int	main(int argc, char **argv)
{
	if (init_params(argc, argv))
		return (ERR);
	if (start_philosohpers() > 0)
	{
		g_data.i = -1;
		while (++g_data.i < g_data.number_of_philosophers)
			pthread_mutex_destroy(&g_data.philo[g_data.i].fork);
		pthread_mutex_destroy(&g_data.mutex_print);
		free (g_data.philo);
		free (g_data.t);
	}
	return (OK);
}
