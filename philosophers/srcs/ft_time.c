/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:45:40 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/26 12:58:42 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_timestamp(void)
{
	struct timeval	now;
	static long		start;

	gettimeofday(&now, 0);
	if (start == 0)
		start = now.tv_sec * 1000 + now.tv_usec / 1000;
	return ((now.tv_sec * 1000 + now.tv_usec / 1000) - start);
}

void	ft_usleep(long time, t_list *philo)
{
	long	start;
	long	curent;
	long	res;

	(void) philo;
	start = ft_get_timestamp();
	res = 0;
	while (res < time)
	{
		usleep(50);
		curent = ft_get_timestamp();
		res = curent - start;
	}
}
