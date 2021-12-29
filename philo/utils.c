/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:06:20 by prranges          #+#    #+#             */
/*   Updated: 2021/11/08 15:06:22 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int			min;
	long int	res;

	min = 1;
	res = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			min *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
		if ((res * min) < ((2147483647 * -1) - 1))
			return (0);
		if ((res * min) > 2147483647)
			return (-1);
	}
	return ((int)res * min);
}

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
	}
	return (0);
}

long	current_time(void)
{
	gettimeofday(&g_data.time, NULL);
	return (g_data.time.tv_sec * 1000 + g_data.time.tv_usec / 1000);
}

void	my_sleep(int time)
{
	long	sleep;

	sleep = current_time() + time;
	while (current_time() < sleep)
		usleep(100);
}
