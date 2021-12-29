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

#include "philo_bonus.h"

void	*monitoring(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	while (1)
	{
		if (p->last_eat_time == 0)
			p->last_eat_time = p->start_time;
		sem_wait(g_data.end);
		g_data.starving = current_time() - p->last_eat_time;
		if (g_data.starving > g_data.time_to_die)
		{
			sem_wait(g_data.print);
			printf("%ld %d is died\n", current_time(), p->id);
			printf("Philosopher %d ", p->id);
			printf("starved for %ld ms\n", g_data.starving);
			kill(0, SIGINT);
			return (OK);
		}
		sem_post(g_data.end);
		usleep(999);
	}
	return (OK);
}

void	routine(void *arg)
{
	t_philo		*p;
	int			limit_of_meals;

	p = (t_philo *)arg;
	pthread_create(&g_data.monitor, NULL, monitoring, p);
	limit_of_meals = g_data.number_of_times_must_eat;
	while (limit_of_meals)
	{
		sem_wait(g_data.fork);
		print_status(p->id, TAKE_FORK);
		print_status(p->id, TAKE_FORK);
		print_status(p->id, EATING);
		p->last_eat_time = current_time();
		my_sleep(g_data.time_to_eat);
		sem_post(g_data.fork);
		print_status(p->id, SLEEPING);
		my_sleep(g_data.time_to_sleep);
		print_status(p->id, THINKING);
		if (limit_of_meals != LOOP)
			limit_of_meals--;
		usleep(333);
	}
	exit (0);
}

int	init_philosophers(void)
{
	g_data.i = 0;
	while (g_data.i < g_data.number_of_philosophers)
	{
		g_data.philo[g_data.i].last_eat_time = 0;
		g_data.philo[g_data.i].id = g_data.i + 1;
		g_data.i++;
	}
	return (OK);
}

int	start_philosohpers(void)
{
	int	result;

	g_data.philo = malloc(sizeof(t_philo) * g_data.number_of_philosophers);
	if (!g_data.philo)
		return (M_ERR);
	init_philosophers();
	open_semaphore();
	result = create_processes();
	close_semaphore();
	return (result);
}

int	main(int argc, char **argv)
{
	if (init_params(argc, argv))
		return (ERR);
	if (start_philosohpers() != M_ERR)
		free (g_data.philo);
	return (OK);
}
