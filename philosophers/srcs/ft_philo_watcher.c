/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_watcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:26:35 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/03 11:53:05 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_looking_for_death(t_rules *rules)
{
	t_list	*lfd;

	rules->checker = 0;
	while (1)
	{
		lfd = rules->start;
		while (lfd != NULL)
		{
			if (ft_dead_or_no(rules, lfd) == 1)
				break ;
			lfd = lfd->next;
		}
		pthread_mutex_lock(&rules->mutex_finish);
		if (rules->check_dead == 1 || rules->check_finish == 1)
		{
			pthread_mutex_unlock(&rules->mutex_finish);
			break ;
		}
		else
			pthread_mutex_unlock(&rules->mutex_finish);
	}
}

int	ft_dead_or_no(t_rules *rules, t_list *lfd)
{
	long	tmp_last_meal;

	ft_get_last_meal(rules, &tmp_last_meal, lfd);
	if (lfd->finish == 0)
	{
		pthread_mutex_unlock(&rules->mutex_finish);
		if ((rules->check_timer - tmp_last_meal) > rules->t_die)
		{
			ft_philo_died(rules, lfd->name);
			return (1);
		}
	}
	else
		pthread_mutex_unlock(&rules->mutex_finish);
	if (ft_check_all_finish(rules) == 0)
		return (1);
	return (0);
}

void	ft_get_last_meal(t_rules *rules, long *tmp_last_meal, t_list *lfd)
{
	pthread_mutex_lock(&rules->mutex_timestamp);
	rules->check_timer = ft_get_timestamp();
	pthread_mutex_unlock(&rules->mutex_timestamp);
	pthread_mutex_lock(&rules->mutex_read_meal);
	*tmp_last_meal = lfd->last_meal;
	pthread_mutex_unlock(&rules->mutex_read_meal);
	pthread_mutex_lock(&rules->mutex_finish);
}

void	ft_philo_died(t_rules *rules, int name)
{
	t_list	*tmp;

	tmp = rules->start;
	printf("[%ld] | [%d] died\n", rules->check_timer, name);
	while (tmp != NULL)
	{
		pthread_mutex_lock(&rules->mutex_alive);
		tmp->alive = 1;
		pthread_mutex_unlock(&rules->mutex_alive);
		tmp = tmp->next;
	}
	rules->check_dead = 1;
}

int	ft_check_all_finish(t_rules *rules)
{
	t_list	*tmp;

	tmp = rules->start;
	while (tmp != NULL)
	{
		pthread_mutex_lock(&rules->mutex_finish);
		if (tmp->finish == 1)
		{
			rules->check_finish = 1;
			pthread_mutex_unlock(&rules->mutex_finish);
		}
		else
		{
			rules->check_finish = 0;
			pthread_mutex_unlock(&rules->mutex_finish);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
