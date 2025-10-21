/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:50:06 by smolines          #+#    #+#             */
/*   Updated: 2024/06/04 20:16:33 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// rotate stack_a before push
void	rotation_a(t_list **stack_a, t_list *target_node)
{
	while (*stack_a != target_node)
	{
		if (target_node->above_median == 0)
			ra (stack_a);
		else
			rra(stack_a);
	}
}

// rotate stack_b before push
void	rotation_b(t_list **stack_b, t_list *cheapest_node)
{
	while (*stack_b != cheapest_node)
	{
		if (cheapest_node->above_median == 0)
			rb (stack_b);
		else
			rrb(stack_b);
	}
}

// optimize rotation in botch stacks 
void	rotation_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	while (*stack_b != cheapest_node && *stack_a != cheapest_node->target)
		rr(stack_a, stack_b);
	refresh_position (*stack_a);
	refresh_position (*stack_b);
}

// optimize reverse rotation in botch stacks 
void	rev_rotation_both(t_list **stack_a, t_list **stack_b,
		t_list *cheapest_node)
{
	while (*stack_b != cheapest_node && *stack_a != cheapest_node->target)
		rrr(stack_a, stack_b);
	refresh_position (*stack_a);
	refresh_position (*stack_b);
}

// move the nodes to have the cheapest and its target to the top then push
void	move_to_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = find_cheapest_node(*stack_b);
	if (cheapest_node->above_median == 0
		&& cheapest_node->target->above_median == 0)
		rotation_both (stack_a, stack_b, cheapest_node);
	else if (cheapest_node->above_median == 1
		&& cheapest_node->target->above_median == 1)
		rev_rotation_both (stack_a, stack_b, cheapest_node);
	rotation_a (stack_a, cheapest_node->target);
	rotation_b (stack_b, cheapest_node);
	pa (stack_a, stack_b);
}
