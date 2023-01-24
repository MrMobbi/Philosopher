/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:07:07 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/24 16:18:56 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(int ac, char **av)
{
	int	i;
	int	error;

	i = 1;
	error = 0;
	if (ac != 6)
	{
		ft_display_error(1, 0);
		return (1);
	}
	while (i < ac)
	{
		error = ft_check_error(av[i]);
		if (error != 0)
			break ;
		i++;
	}
	if (error != 0)
	{
		ft_display_error(error, i);
		return (1);
	}
	return (0);
}

void	ft_display_error(int code_error, int arg)
{
	if (arg != 0)
		printf("Erreur pour l'argument Numero [%d] : ", arg);
	if (code_error == 1)
		printf("Mauvais nombre d'arguments\n");
	else if (code_error == 2)
		printf("Veulliez entrer un nombre ou un chiffre\n");
	else if (code_error == 3)
		printf("Les nombres inferieur a 0 sont interdit\n");
	else if (code_error == 4)
		printf("Merci d'entre le nombre sans + devant\n");
	else if (code_error == 5)
		printf("Le nombre entre est en dehors de la range du int\n");
	else if (code_error == 6)
		printf("Le chiffre 0 est interdit!\n");
}

void	ft_display_error_launch(int code_error)
{
	if (code_error == 1)
		printf("Erreur lors de la creation des mutexs\n");
	else if (code_error == 2)
		printf("Erreur lors de la creation des threads\n");
	else if (code_error == 3)
		printf("Erreur lors du join des threads\n");
	else if (code_error == 4)
		printf("Erreur lors de la destruction des mutexs\n");
}
