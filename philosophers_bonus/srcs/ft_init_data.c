/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:00:12 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/26 17:59:19 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_data(char **av, t_rules *rules)
{
	int	i;

	i = 1;
	rules->nbr_philo = ft_atoi(av[1]);
	rules->t_die = ft_atoi(av[2]);
	rules->t_eat = ft_atoi(av[3]);
	rules->t_sleep = ft_atoi(av[4]);
	rules->n_meal = ft_atoi(av[5]);
	rules->start = ft_lstnew(rules, i);
	rules->checker = 1;
	rules->check_dead = 0;
	rules->check_finish = 0;
	i++;
	while (i <= rules->nbr_philo)
	{
		ft_lstadd_back(&rules->start, ft_lstnew(rules, i));
		i++;
	}
	ft_add_left(rules);
}
