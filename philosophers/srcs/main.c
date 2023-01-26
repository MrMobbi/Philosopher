/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:34:29 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/25 17:10:34 by mjulliat         ###   ########.fr       */
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
	return (0);
}
