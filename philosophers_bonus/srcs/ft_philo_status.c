/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:55:21 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/31 10:26:03 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_list *philo)
{
	pthread_mutex_lock(&philo->rules->mutex_timestamp);
	philo->curent = ft_get_timestamp();
	pthread_mutex_unlock(&philo->rules->mutex_timestamp);
	philo->now = philo->curent - philo->start;
	pthread_mutex_lock(&philo->rules->mutex_alive);
	if (philo->alive == 0)
	{
		printf("[%ld] | [%d] is thinking\n", philo->now, philo->name);
		pthread_mutex_unlock(&philo->rules->mutex_alive);
	}
	else
		pthread_mutex_unlock(&philo->rules->mutex_alive);
	pthread_mutex_lock(&philo->left->mutex_fork);
	ft_take_fork(philo);
	pthread_mutex_lock(&philo->mutex_fork);
	ft_take_fork(philo);
	ft_eat(philo);
	pthread_mutex_unlock(&philo->left->mutex_fork);
	pthread_mutex_unlock(&philo->mutex_fork);
	ft_sleep(philo);
}

void	ft_eat(t_list *philo)
{
	pthread_mutex_lock(&philo->rules->mutex_timestamp);
	philo->curent = ft_get_timestamp();
	pthread_mutex_unlock(&philo->rules->mutex_timestamp);
	philo->now = philo->curent - philo->start;
	pthread_mutex_lock(&philo->rules->mutex_alive);
	if (philo->alive == 0)
	{
		printf("[%ld] | [%d] is eating\n", philo->now, philo->name);
		pthread_mutex_unlock(&philo->rules->mutex_alive);
	}
	else
		pthread_mutex_unlock(&philo->rules->mutex_alive);
	pthread_mutex_lock(&philo->rules->mutex_timestamp);
	pthread_mutex_lock(&philo->rules->mutex_read_meal);
	philo->last_meal = ft_get_timestamp();
	pthread_mutex_unlock(&philo->rules->mutex_timestamp);
	pthread_mutex_unlock(&philo->rules->mutex_read_meal);
	ft_usleep(philo->rules_t_eat, philo);
}

void	ft_sleep(t_list *philo)
{
	pthread_mutex_lock(&philo->rules->mutex_timestamp);
	philo->curent = ft_get_timestamp();
	pthread_mutex_unlock(&philo->rules->mutex_timestamp);
	philo->now = philo->curent - philo->start;
	pthread_mutex_lock(&philo->rules->mutex_alive);
	if (philo->alive == 0)
	{
		printf("[%ld] | [%d] is sleeping\n", philo->now, philo->name);
		pthread_mutex_unlock(&philo->rules->mutex_alive);
	}
	else
		pthread_mutex_unlock(&philo->rules->mutex_alive);
	ft_usleep(philo->rules_t_sleep, philo);
}

void	ft_take_fork(t_list *philo)
{
	pthread_mutex_lock(&philo->rules->mutex_timestamp);
	philo->curent = ft_get_timestamp();
	pthread_mutex_unlock(&philo->rules->mutex_timestamp);
	philo->now = philo->curent - philo->start;
	pthread_mutex_lock(&philo->rules->mutex_alive);
	if (philo->alive == 0)
	{
		printf("[%ld] | [%d] has taken a fork\n", philo->now, philo->name);
		pthread_mutex_unlock(&philo->rules->mutex_alive);
	}
	else
		pthread_mutex_unlock(&philo->rules->mutex_alive);
}
