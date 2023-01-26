/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:45:40 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/25 18:28:28 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_timestamp_thread(t_list *philo)
{
	struct timeval	now;
	static long		start;
	
	pthread_mutex_lock(&philo->mutex_timestamp);
	gettimeofday(&now, 0);
	pthread_mutex_unlock(&philo->mutex_timestamp);
	if (start == 0)
		start = now.tv_sec * 1000 + now.tv_usec / 1000;
	return ((now.tv_sec * 1000 + now.tv_usec / 1000) - start);
}

void	ft_usleep(long time)
{
	long	start;
	long	curent;
	long	res;

	start = ft_get_timestamp();
	res = 0;
	while (res < time)
	{
		usleep(50);
		curent = ft_get_timestamp();
		res = curent - start;
	}
}
