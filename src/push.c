/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:50:27 by smolines          #+#    #+#             */
/*   Updated: 2024/06/03 16:50:27 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_list **stack_src, t_list **stack_dest)
{
	t_list	*tmp;

	if (*stack_src == NULL)
		return ;
	tmp = (*stack_src)->next;
	(*stack_src)->next = *stack_dest;
	*stack_dest = *stack_src;
	*stack_src = tmp;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push (stack_a, stack_b);
	ft_putstr("pb\n");
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push (stack_b, stack_a);
	ft_putstr("pa\n");
}
