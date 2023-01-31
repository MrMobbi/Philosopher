/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_watcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:26:35 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/31 10:47:19 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_noname(t_rules *rules, long *tmp_last_meal, t_list *lfd)
{
	pthread_mutex_lock(&rules->mutex_timestamp);
	rules->check_timer = ft_get_timestamp();
	pthread_mutex_unlock(&rules->mutex_timestamp);
	pthread_mutex_lock(&rules->mutex_read_meal);
	*tmp_last_meal = lfd->last_meal;
	pthread_mutex_unlock(&rules->mutex_read_meal);
}

void	ft_looking_for_death(t_rules *rules)
{
	t_list	*lfd;
	long	tmp_last_meal;

	rules->checker = 0;
	while (1)
	{
		lfd = rules->start;
		while (lfd != NULL)
		{
			ft_noname(rules, &tmp_last_meal, lfd);
			if (lfd->finish == 0)
			{
				if ((rules->check_timer - tmp_last_meal) > rules->t_die)
				{
					ft_philo_died(rules, lfd->name);
					break ;
				}
			}
			if (ft_check_all_finish(rules) == 0)
				break ;
			lfd = lfd->next;
		}
		if (rules->check_dead == 1 || rules->check_finish == 1)
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
