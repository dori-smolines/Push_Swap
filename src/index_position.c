/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:49:56 by smolines          #+#    #+#             */
/*   Updated: 2024/06/04 20:16:16 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// index la stack avec les positions de tri finales
int	ft_index(t_list *lst)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp2;

	if (lst == NULL)
		return (0);
	i = ft_lstsize(lst);
	tmp2 = lst;
	while (tmp2)
	{
		tmp = lst;
		tmp2->index = i;
		while (tmp)
		{
			if (tmp2->value > tmp->value)
				tmp2->index--;
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
	return (0);
}

int	refresh_position(t_list *lst)
{
	int	median;
	int	i;

	i = 0;
	median = ft_lstsize(lst) / 2;
	while (lst)
	{
		lst->position = i;
		if (i <= median)
			lst->above_median = 0;
		else
			lst->above_median = 1;
		i++;
		lst = lst->next;
	}
	return (0);
}

// trouve le plus petit node cad celui avec index le plus faible
t_list	*find_min(t_list *lst)
{
	t_list	*node_min;
	long	min;

	if (!lst)
		return (NULL);
	min = LONG_MAX;
	while (lst)
	{
		if (lst->value < min)
		{
			min = lst->value;
			node_min = lst;
		}
		lst = lst->next;
	}
	return (node_min);
}

t_list	*find_max(t_list *lst)
{
	t_list	*node_max;
	long	max;

	if (!lst)
		return (NULL);
	max = LONG_MIN;
	while (lst)
	{
		if (lst->value > max)
		{
			max = lst->value;
			node_max = lst;
		}
		lst = lst->next;
	}
	return (node_max);
}

// trouver le nod dans A qui a l'index le plus immediatement eleve
void	find_target(t_list *stack_a, t_list *stack_b)
{
	t_list	*target_node;
	t_list	*tmp_a;
	long	target_index;

	while (stack_b)
	{
		target_index = LONG_MAX;
		tmp_a = stack_a;
		while (tmp_a)
		{
			if ((tmp_a->value > stack_b->value)
				&& (tmp_a->value < target_index))
			{
				target_index = tmp_a->value;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (target_index == LONG_MAX)
			stack_b->target = find_min(stack_a);
		else
			stack_b->target = target_node;
		stack_b = stack_b->next;
	}
}
