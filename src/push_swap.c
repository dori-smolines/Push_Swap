/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:50:23 by smolines          #+#    #+#             */
/*   Updated: 2024/06/06 10:13:26 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	finish_sort_a(t_list **stack_a)
{
	t_list	*node_min;

	if (!stack_a)
		return ;
	node_min = find_min (*stack_a);
	if (node_min->above_median == 0)
	{
		while (*stack_a != node_min)
			ra (stack_a);
	}
	else
	{
		while (*stack_a != node_min)
			rra (stack_a);
	}
}

int	sort(t_list **stack_a, t_list **stack_b, int len_a)
{
	if (len_a == 1)
		return (0);
	if (stack_is_sorted(*stack_a) == 1)
		return (0);
	if (len_a == 2)
	{
		sa (stack_a);
		return (0);
	}
	if (len_a == 3)
		sort_three_stacka (stack_a);
	else
		push_swap (stack_a, stack_b);
	return (0);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int		len;

	len = ft_lstsize(*stack_a);
	while (len > 3)
	{
		pb (stack_a, stack_b);
		len--;
	}
	sort_three_stacka(stack_a);
	while (*stack_b)
	{
		refresh_nodes(*stack_a, *stack_b);
		move_to_push (stack_a, stack_b);
	}
	refresh_position (*stack_a);
	finish_sort_a(stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		len_a;

	if ((argc < 2) || (argc == 2 && !argv[1][0]))
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_initialisation (argc, argv, stack_a, 1);
	if (stack_a == NULL)
		return (0);
	len_a = ft_lstsize(stack_a);
	if (len_a == 1)
	{
		free_lst (&stack_a);
		return (0);
	}
	else
		sort (&stack_a, &stack_b, len_a);
	free_lst (&stack_a);
	free_lst (&stack_b);
	return (0);
}
