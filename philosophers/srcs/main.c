/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:34:29 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/23 15:57:07 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int		code_error;
	t_rules	rules;

	if (ft_error(ac, av) == 1)
		return (0);
	ft_init_data(av, &rules);
	code_error = ft_launcher(&rules);
	if (code_error != 0)
	{
		ft_display_error_launch(code_error);
		return (0);
	}
	ft_free_lst(rules.start);
	printf("Nbr of philo : %d\n", rules.nbr_philo);
	printf("Time before dying : %d\n", rules.t_die);
	printf("Time to eat : %d\n", rules.t_eat);
	printf("Time to sleep : %d\n", rules.t_sleep);
	printf("Number of meals : %d\n", rules.n_meal);
	return (0);
}
