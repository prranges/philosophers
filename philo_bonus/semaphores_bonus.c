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

#include "philo_bonus.h"

int	open_semaphore(void)
{
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("end");
	g_data.fork = sem_open("fork", O_CREAT | O_RDWR, 0660, \
						   g_data.number_of_philosophers / 2);
	g_data.print = sem_open("print", O_CREAT | O_RDWR, 0660, 1);
	g_data.end = sem_open("end", O_CREAT | O_RDWR, 0660, 1);
	return (OK);
}

int	close_semaphore(void)
{
	sem_close(g_data.fork);
	sem_close(g_data.print);
	sem_close(g_data.end);
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("end");
	return (OK);
}

int	create_processes(void)
{
	int	status;

	g_data.i = 0;
	while (g_data.i < g_data.number_of_philosophers)
	{
		g_data.philo[g_data.i].pid = fork();
		g_data.philo[g_data.i].start_time = current_time();
		if (g_data.philo->pid < 0)
			return (ERR);
		else if (!g_data.philo[g_data.i].pid)
			routine(&g_data.philo[g_data.i]);
		g_data.i++;
	}
	g_data.i = 0;
	while (g_data.i < g_data.number_of_philosophers)
	{
		waitpid(-1, &status, 0);
		g_data.i++;
	}
	printf("Every philosopher ate %d times\n", g_data.number_of_times_must_eat);
	return (OK);
}
