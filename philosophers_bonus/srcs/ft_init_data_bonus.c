/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:00:12 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/02 18:16:13 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init_data(char **av, t_rules *rules)
{
	rules->nbr_philo = ft_atoi(av[1]);
	rules->t_die = ft_atoi(av[2]);
	rules->t_eat = ft_atoi(av[3]);
	rules->t_sleep = ft_atoi(av[4]);
	rules->n_meal = ft_atoi(av[5]);
	rules->pid_philo = malloc(sizeof(int) * rules->nbr_philo);
}

int	ft_init_sem(t_rules *rules)
{
	sem_unlink("/sem_fork");
	sem_unlink("/sem_write");
	sem_unlink("/sem_exit");
	sem_unlink("/sem_dead");
	sem_unlink("/sem_begin");
	rules->fork = sem_open("/sem_fork", O_CREAT, 0664, rules->nbr_philo);
	rules->write = sem_open("/sem_write", O_CREAT, 0664, 1);
	rules->exit = sem_open("/sem_exit", O_CREAT, 0664, 0);
	rules->dead = sem_open("/sem_dead", O_CREAT, 0664, 1);
	rules->begin = sem_open("/sem_begin", O_CREAT, 0664, 0);
	return (0);
}
