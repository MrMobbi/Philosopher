/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:00:12 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/23 16:44:42 by mjulliat         ###   ########.fr       */
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
	i++;
	while (i <= rules->nbr_philo)
	{
		ft_lstadd_back(&rules->start, ft_lstnew(rules, i));
		i++;
	}
	ft_add_left_and_right(rules);
}
