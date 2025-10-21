/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:49:40 by smolines          #+#    #+#             */
/*   Updated: 2024/06/04 20:10:47 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// refresh stack positions, target, cost and cheapest node
void	refresh_nodes(t_list *stack_a, t_list *stack_b)
{
	refresh_position(stack_a);
	refresh_position(stack_b);
	find_target(stack_a, stack_b);
	calculate_cost(stack_a, stack_b);
	find_cheapest_node(stack_b);
}

//calculate push cost
void	calculate_cost(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize (stack_a);
	len_b = ft_lstsize (stack_b);
	while (stack_b)
	{
		stack_b->push_cost = stack_b->position;
		if (stack_b->above_median == 1)
			stack_b->push_cost = len_b - (stack_b->position);
		if (stack_b->target->above_median == 0)
			stack_b->push_cost += stack_b->target->position;
		else
			stack_b->push_cost += len_a - (stack_b->target->position);
		stack_b = stack_b->next;
	}
}

// repere le premier node au coup le moins eleve
t_list	*find_cheapest_node(t_list *stack_b)
{
	long	cheapest_cost;
	t_list	*cheapest_node;

	cheapest_cost = LONG_MAX;
	while (stack_b)
	{
		if (stack_b->push_cost < cheapest_cost)
		{
			cheapest_node = stack_b;
			cheapest_cost = stack_b->push_cost;
		}
		stack_b = stack_b->next;
	}
	cheapest_node->ischeapest = 1;
	return (cheapest_node);
}

int	sort_three_stacka(t_list **lst)
{
	t_list	*max;

	if (!(*lst))
		return (1);
	max = find_max (*lst);
	if (*lst == max)
		ra (lst);
	else if ((*lst)->next == max)
		rra (lst);
	if ((*lst)->value > (*lst)->next->value)
		sa (lst);
	return (0);
}
