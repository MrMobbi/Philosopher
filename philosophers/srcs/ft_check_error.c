/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:12:32 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/26 17:59:05 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_error(char *str)
{
	if (ft_check_if_digit(str) == 1)
		return (2);
	else if (ft_check_if_digit(str) == 2)
		return (3);
	else if (ft_check_if_digit(str) == 3)
		return (4);
	if (ft_check_max_int(str) == 1)
		return (5);
	if (ft_strlen(str) == 1)
	{
		if (*str == '0')
			return (6);
	}
	return (0);
}

int	ft_check_if_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
		return (2);
	if (str[i] == '+')
		return (3);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_check_max_int(char *str)
{
	if (ft_strlen(str) > 10)
		return (1);
	else if (ft_strlen(str) == 10)
	{
		if (ft_strcmp(str, MAX_INT) > 0)
			return (1);
	}
	return (0);
}
