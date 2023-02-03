/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:16:27 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/03 11:21:06 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_launcher(t_rules *rules)
{
	int	i;

	i = 0;
	if (ft_init_sem(rules) != 0)
		return (1);
	rules->start = ft_get_timestamp();
	while (i < rules->nbr_philo)
	{
		rules->pid_philo[i] = fork();
		if (rules->pid_philo[i] < 0)
			return (2);
		if (rules->pid_philo[i] == 0)
			ft_routine(rules, i + 1);
		i++;
	}
	return (0);
}

void	ft_routine(t_rules *rules, int name)
{
	int		i;
	t_philo	philo;

	i = 0;
	philo.name = name;
	philo.rules = rules;
	sem_wait(philo.rules->begin);
	philo.debut = ft_get_timestamp();
	if (philo.name % 2 == 0)
		usleep(1000);
	if (philo.rules->nbr_philo == 1)
		ft_one_philo(&philo);
	while (i < rules->n_meal)
	{
		ft_think(&philo);
		i++;
	}
	sem_post(philo.rules->exit);
	while (1)
		continue ;
}

void	ft_one_philo(t_philo *philo)
{
	philo->curent = ft_get_timestamp();
	philo->now = philo->curent - philo->debut;
	printf("[%ld] | [%d] is thinking\n", philo->now, philo->name);
	printf("[%ld] | [%d] has taken a fork\n", philo->now, philo->name);
	ft_usleep((philo->rules->t_die + 1) - philo->now);
	philo->curent = ft_get_timestamp();
	philo->now = philo->curent - philo->debut;
	printf("[%ld] | [%d] is dead\n", philo->now, philo->name);
	sem_post(philo->rules->exit);
	while (1)
		(void) philo;
}
