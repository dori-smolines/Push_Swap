/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:50:33 by smolines          #+#    #+#             */
/*   Updated: 2024/06/03 16:50:33 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_list **lst)
{
	t_list	*last;
	t_list	*tmp;

	if (lst == NULL || (*lst)->next == NULL)
		return ;
	last = NULL;
	last = ft_lstlast(*lst);
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	ra(t_list **stack_a)
{
	rotate (stack_a);
	ft_putstr("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate (stack_b);
	ft_putstr("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate (stack_a);
	rotate (stack_b);
	ft_putstr("rr\n");
}
