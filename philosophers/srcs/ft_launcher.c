/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:36:29 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/26 15:40:01 by mjulliat         ###   ########.fr       */
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
	code_error = ft_mutex(rules);
	if (code_error != 0)
		return (code_error);
	while (i < rules->nbr_philo)
	{
		if (pthread_create(&tmp->thread_id, NULL, &routine, tmp) != 0)
			return (4);
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
	pthread_mutex_lock(&philo->rules->mutex_timestamp);
	philo->start = ft_get_timestamp();
	pthread_mutex_unlock(&philo->rules->mutex_timestamp);
	while (i < philo->rules_n_meal)
	{
		if (philo->name % 2 == 0 && i == 0)
			usleep(1000);
		if (philo->alive == 1)
			break ;
		ft_think(philo);
		i++;
	}
	philo->finish = 1;
	return (NULL);
}
