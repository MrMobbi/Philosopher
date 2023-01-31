/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:28:26 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/26 18:00:01 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_list	*ft_lstnew(t_rules *rules, int name)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new->next = NULL;
	new->name = name;
	new->alive = 0;
	new->rules = rules;
	new->last_meal = 0;
	new->finish = 0;
	new->rules_t_die = rules->t_die;
	new->rules_t_eat = rules->t_eat;
	new->rules_t_sleep = rules->t_sleep;
	new->rules_n_meal = rules->n_meal;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *nw)
{
	t_list	*node;

	node = *lst;
	if (node == NULL)
		node = nw;
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = nw;
	}
}

void	ft_add_left(t_rules *rules)
{
	t_list	*tmp;

	tmp = rules->start;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			tmp->left = rules->start;
		else
			tmp->left = tmp->next;
		tmp = tmp->next;
	}
}

void	ft_free_lst(t_list *list)
{
	t_list	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
