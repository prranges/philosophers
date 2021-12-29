/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:51:07 by prranges          #+#    #+#             */
/*   Updated: 2021/11/08 14:51:11 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_params(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (ERR);
	}
	if (ft_atoi(argv[1]) < 1)
	{
		printf("Error: Wrong number of philosophers\n");
		return (ERR);
	}
	while (argv[++i])
	{
		if (ft_isnumber(argv[i]))
		{
			printf("Error: Argument %d is invalid\n", i);
			return (ERR);
		}
	}
	return (0);
}

int	init_params(int argc, char **argv)
{
	if (check_params(argc, argv))
		return (ERR);
	g_data.i = 0;
	g_data.number_of_philosophers = ft_atoi(argv[1]);
	g_data.time_to_die = ft_atoi(argv[2]);
	g_data.time_to_eat = ft_atoi(argv[3]);
	g_data.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		g_data.number_of_times_must_eat = ft_atoi(argv[5]);
	else
		g_data.number_of_times_must_eat = LOOP;
	return (0);
}
