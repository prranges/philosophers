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

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
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
# define END		5
# define LOOP		-1

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
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
	int				current_times_of_eat;
	long			starving;
	int				dead_philo;
	pthread_t		*t;
	pthread_mutex_t	mutex_print;
	struct timeval	time;
}					t_data;

t_data	g_data;

int		ft_atoi(const char *str);
int		ft_isdigit(int n);
int		ft_isnumber(char *str);
void	print_status(int num, int id);
int		init_params(int argc, char **argv);
long	current_time(void);
void	my_sleep(int time);
int		create_threads(int id);
void	join_threads(void);
void	detach_threads(int i);
void	*routine(void *arg);
void	print_status(int num, int id);

#endif
