/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_status_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:57:03 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/03 11:09:48 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_think(t_philo *philo)
{
	philo->curent = ft_get_timestamp();
	philo->now = philo->curent - philo->debut;
	philo->last_meal = philo->now;
	sem_wait(philo->rules->dead);
	sem_wait(philo->rules->write);
	printf("[%ld] | [%d] is thinking\n", philo->now, philo->name);
	sem_post(philo->rules->write);
	sem_post(philo->rules->dead);
	sem_wait(philo->rules->fork);
	ft_fork_taken(philo);
	sem_wait(philo->rules->fork);
	ft_fork_taken(philo);
	ft_eat(philo);
	sem_post(philo->rules->fork);
	sem_post(philo->rules->fork);
	ft_sleep(philo);
}

void	ft_eat(t_philo *philo)
{
	philo->curent = ft_get_timestamp();
	philo->now = philo->curent - philo->debut;
	sem_wait(philo->rules->dead);
	ft_dead_or_no(philo, philo->rules->t_eat);
	sem_wait(philo->rules->write);
	printf("[%ld] | [%d] is eating\n", philo->now, philo->name);
	sem_post(philo->rules->write);
	sem_post(philo->rules->dead);
	ft_usleep(philo->rules->t_eat);
	philo->last_meal = (ft_get_timestamp() - philo->debut);
}

void	ft_sleep(t_philo *philo)
{
	philo->curent = ft_get_timestamp();
	philo->now = philo->curent - philo->debut;
	sem_wait(philo->rules->dead);
	ft_dead_or_no(philo, philo->rules->t_sleep);
	sem_wait(philo->rules->write);
	printf("[%ld] | [%d] is sleeping\n", philo->now, philo->name);
	sem_post(philo->rules->write);
	sem_post(philo->rules->dead);
	ft_usleep(philo->rules->t_sleep);
}

void	ft_fork_taken(t_philo *philo)
{
	philo->curent = ft_get_timestamp();
	philo->now = philo->curent - philo->debut;
	sem_wait(philo->rules->write);
	printf("[%ld] | [%d] has taken a fork\n", philo->now, philo->name);
	sem_post(philo->rules->write);
}

void	ft_dead_or_no(t_philo *philo, long time_action)
{
	long	t_die;
	int		i;

	i = 0;
	t_die = philo->rules->t_die;
	if ((philo->now - philo->last_meal) + time_action > t_die)
	{
		ft_usleep((philo->rules->t_die + 1) - philo->now);
		philo->curent = ft_get_timestamp();
		philo->now = philo->curent - philo->debut;
		sem_wait(philo->rules->write);
		printf("[%ld] | [%d] is dead\n", philo->now, philo->name);
		sem_post(philo->rules->write);
		while (i < philo->rules->nbr_philo)
		{
			sem_post(philo->rules->exit);
			i++;
		}
		while (1)
			(void) philo;
	}
}
