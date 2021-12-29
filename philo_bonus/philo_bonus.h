/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:42:43 by prranges          #+#    #+#             */
/*   Updated: 2021/10/11 13:42:48 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <unistd.h>
# include <sys/time.h>

# define OK			0
# define M_ERR		-1
# define ERR		1
# define TAKE_FORK	0
# define EATING		1
# define SLEEPING	2
# define THINKING	3
# define DEAD		4
# define LOOP		-1

typedef struct s_philo
{
	int				id;
	int				pid;
	long			start_time;
	long			last_eat_time;
}					t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				i;
	int				number_of_philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				number_of_times_must_eat;
	long			starving;
	sem_t			*fork;
	sem_t			*print;
	sem_t			*end;
	pthread_t		monitor;
	struct timeval	time;
}					t_data;

t_data	g_data;

int		ft_atoi(const char *str);
int		ft_isdigit(int n);
int		ft_isnumber(char *str);
void	print_status(int num, int id);
int		init_params(int argc, char **argv);
int		open_semaphore(void);
int		close_semaphore(void);
int		create_processes(void);
long	current_time(void);
void	my_sleep(int time);
void	routine(void *arg);
void	print_status(int num, int id);

#endif
