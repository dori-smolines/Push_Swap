/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:50:37 by smolines          #+#    #+#             */
/*   Updated: 2024/06/03 16:50:37 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_list **lst)
{
	t_list	*tmp;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
}

void	sa(t_list **stack_a)
{
	swap (stack_a);
	ft_putstr("sa\n");
}

void	sb(t_list **stack_b)
{
	swap (stack_b);
	ft_putstr("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap (stack_a);
	swap (stack_b);
	ft_putstr("ss\n");
}
