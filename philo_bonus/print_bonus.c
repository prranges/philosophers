/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 08:31:40 by prranges          #+#    #+#             */
/*   Updated: 2021/11/10 08:31:41 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static char	*status(int id)
{
	if (id == TAKE_FORK)
		return ("has taken a fork");
	else if (id == EATING)
		return ("is eating");
	else if (id == SLEEPING)
		return ("is sleeping");
	else if (id == THINKING)
		return ("is thinking");
	else
		return ("died");
}

void	print_status(int num, int id)
{
	sem_wait(g_data.print);
	printf("%ld %d %s\n", current_time(), num, status(id));
	sem_post(g_data.print);
}
