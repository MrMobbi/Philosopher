/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:55:21 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/25 18:27:32 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_list *philo)
{
	philo->curent = ft_get_timestamp(philo);
	philo->now = philo->curent - philo->start;
	if (philo->alive == 0)
		printf("[%ld] | [%d] is thinking\n", philo->now, philo->name);
	pthread_mutex_lock(&philo->left->fork_id);
	ft_take_fork(philo);
	pthread_mutex_lock(&philo->fork_id);
	ft_take_fork(philo);
	ft_eat(philo);
	pthread_mutex_unlock(&philo->left->fork_id);
	pthread_mutex_unlock(&philo->fork_id);
	ft_sleep(philo);
}

void	ft_eat(t_list *philo)
{
	philo->curent = ft_get_timestamp(philo);
	philo->now = philo->curent - philo->start;
	if (philo->alive == 0)
		printf("[%ld] | [%d] is eating\n", philo->now, philo->name);
	ft_usleep(philo->rules->t_eat);
	philo->last_meal = ft_get_timestamp(philo);
}

void	ft_sleep(t_list *philo)
{
	philo->curent = ft_get_timestamp(philo);
	philo->now = philo->curent - philo->start;
	if (philo->alive == 0)
		printf("[%ld] | [%d] is sleeping\n", philo->now, philo->name);
	ft_usleep(philo->rules->t_sleep);
}

void	ft_take_fork(t_list *philo)
{
	philo->curent = ft_get_timestamp(philo);
	philo->now = philo->curent - philo->start;
	if (philo->alive == 0)
		printf("[%ld] | [%d] has taken a fork\n", philo->now, philo->name);
}
