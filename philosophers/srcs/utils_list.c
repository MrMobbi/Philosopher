/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:28:26 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/23 16:52:10 by mjulliat         ###   ########.fr       */
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
	new->previous = NULL;
	new->name = name;
	new->rules = rules;
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
		nw->previous = node;
		node->next = nw;
	}
}

void	ft_add_left_and_right(t_rules *rules)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = rules->start;
	tmp2 = rules->start;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			tmp->right = rules->start;
		else
			tmp->right = tmp->next;
		if (tmp->previous == NULL)
		{
			while (tmp2 != NULL)
			{
				tmp->left = tmp2;
				tmp2 = tmp2->next;
			}
		}
		else
			tmp->left = tmp->previous;
		tmp = tmp->next;
	}
}

void	ft_free_lst(t_list *list)
{
	t_list *tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		printf("List free Nbr [%d]\n", tmp->name);
		free(tmp);
	}
}
