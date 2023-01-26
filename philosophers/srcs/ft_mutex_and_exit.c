/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutex_and_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:24:28 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/26 15:35:34 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mutex(t_rules *rules)
{
	t_list	*tmp;

	tmp = rules->start;
	while (tmp != NULL)
	{
		if (pthread_mutex_init(&tmp->mutex_fork, NULL) != 0)
			return (1);
		tmp = tmp->next;
	}
	if (pthread_mutex_init(&rules->mutex_timestamp, NULL) != 0)
		return (2);
	if (pthread_mutex_init(&rules->mutex_read_meal, NULL) != 0)
		return (3);
	return (0);
}

int	ft_exit(t_rules *rules)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = rules->start;
	while (i < rules->nbr_philo)
	{
		if (pthread_join(tmp->thread_id, NULL) != 0)
			return (5);
		if (pthread_mutex_destroy(&tmp->mutex_fork) != 0)
			return (6);
		tmp = tmp->next;
		i++;
	}
	if (pthread_mutex_destroy(&rules->mutex_timestamp))
		return (7);
	if (pthread_mutex_destroy(&rules->mutex_read_meal))
		return (8);
	return (0);
}
