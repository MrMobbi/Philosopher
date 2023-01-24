/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:55:21 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/24 17:09:20 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_list *philo)
{
	printf("[%lu] | [%d] is thinking\n", philo->start, philo->name);
}

void	ft_eat(t_list *philo)
{
	printf("[%lu] | [%d] is eating\n", philo->start, philo->name);
	usleep(philo->rules->t_eat * 1000);
}

void	ft_sleep(t_list *philo)
{
	printf("[%lu] | [%d] is sleeping\n", philo->start, philo->name);
	usleep(philo->rules->t_sleep * 1000);
}
