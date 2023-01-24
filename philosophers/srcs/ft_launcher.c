/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:36:29 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/23 16:35:07 by mjulliat         ###   ########.fr       */
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
		if (pthread_create(&tmp->thread_id, NULL, &routine, tmp) != 0)
			return (1);
		tmp = tmp->next;
		i++;
	}
	code_error = ft_exit(rules);
	if (code_error != 0)
		return (code_error);
	return (0);
}

void	*routine(void *void_list)
{
	t_list	*philo;

	philo = (t_list *)void_list;
	printf("Hello World! from philo Nbr [%d]\n", philo->name);
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
			return (2);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
