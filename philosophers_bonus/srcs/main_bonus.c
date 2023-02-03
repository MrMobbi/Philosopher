/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:34:29 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/03 11:25:36 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_rules	rules;
	int		code_error;

	if (ft_error(ac, av) != 0)
		return (0);
	ft_init_data(av, &rules);
	code_error = ft_launcher(&rules);
	if (code_error != 0)
	{
		ft_display_error_launch(code_error);
		return (0);
	}
	if (ft_parent_checker(&rules) == 0)
		ft_wait_finish(&rules);
	return (0);
}

void	ft_wait_finish(t_rules *rules)
{
	int	i;

	i = 0;
	usleep(1000 * rules->nbr_philo);
	while (i < rules->nbr_philo)
	{
		sem_post(rules->begin);
		i++;
	}
	i = 0;
	while (i < rules->nbr_philo)
	{
		sem_wait(rules->exit);
		i++;
	}
	ft_kill_process(rules);
}

void	ft_kill_process(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nbr_philo)
	{
		kill(rules->pid_philo[i], SIGTERM);
		i++;
	}
	free(rules->pid_philo);
}

int	ft_parent_checker(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nbr_philo)
	{
		if (rules->pid_philo[i] == 0)
			return (1);
		i++;
	}
	return (0);
}
