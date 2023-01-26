/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:36:29 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/25 18:26:42 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_launcher(t_rules *rules)
{
	int		code_error;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = rules->start;
	while (i < rules->nbr_philo)
	{
		if (pthread_mutex_init(&tmp->fork_id, NULL) != 0)
			return (1);
		tmp = tmp->next;
		i++;
	}
	i = 0;
	tmp = rules->start;
	while (i < rules->nbr_philo)
	{
		if (pthread_mutex_init(&tmp->mutex_timestamp, NULL) != 0)
			return (2);
		tmp = tmp->next;
		i++;
	}
	tmp = rules->start;
	i = 0;
	while (i < rules->nbr_philo)
	{
		if (pthread_create(&tmp->thread_id, NULL, &routine, tmp) != 0)
			return (3);
		tmp = tmp->next;
		i++;
	}
	if (rules->checker == 1)
		ft_looking_for_death(rules);
	code_error = ft_exit(rules);
	if (code_error != 0)
		return (code_error);
	return (0);
}

void	*routine(void *void_list)
{
	int		i;
	t_list	*philo;

	i = 0;
	philo = (t_list *)void_list;
	philo->start = ft_get_timestamp(philo);
	while (i < philo->rules->n_meal)
	{
		if (philo->alive == 1)
			break ;
		ft_think(philo);
		i++;
	}
	philo->finish = 1;
	return (NULL);
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
			return (4);
		if (pthread_mutex_destroy(&tmp->fork_id) != 0)
			return (5);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	ft_check_if_finish(t_rules *rules)
{
	t_list	*tmp;

	tmp = rules->start;
	while (tmp != NULL)
	{
		if (tmp->finish == 1)
			rules->check_finish = 1;
		else
		{
			rules->check_finish = 0;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_looking_for_death(t_rules *rules)
{
	t_list	*lfd;

	rules->checker = 0;
	while (1)
	{
		lfd = rules->start;
		while (lfd != NULL)
		{
			rules->check_timer = ft_get_timestamp();
			if ((rules->check_timer - lfd->last_meal) > rules->t_die)
			{
				ft_philo_died(rules, lfd->name);
				break ;
			}
			lfd = lfd->next;
			if (ft_check_if_finish(rules) == 0)
				break ;
		}
		if (rules->check_dead == 1)
			break ;
		if (rules->check_finish == 1)
			break ;
	}
}

void	ft_philo_died(t_rules *rules, int name)
{
	t_list	*tmp;

	tmp = rules->start;
	printf("[%ld] | [%d] died\n", rules->check_timer, name);
	while (tmp != NULL)
	{
		tmp->alive = 1;
		tmp = tmp->next;
	}
	rules->check_dead = 1;
}
