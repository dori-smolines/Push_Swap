/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:50:30 by smolines          #+#    #+#             */
/*   Updated: 2024/06/03 16:50:50 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverse_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*beforelast;

	beforelast = NULL;
	last = NULL;
	if ((lst == NULL) || ((*lst)->next == NULL))
		return ;
	last = ft_lstlast(*lst);
	beforelast = ft_lstbeforelast(*lst);
	(last)->next = *lst;
	*lst = last;
	beforelast->next = NULL;
}

void	rra(t_list **stack_a)
{
	reverse_rotate (stack_a);
	ft_putstr("rra\n");
}

void	rrb(t_list **stack_b)
{
	reverse_rotate (stack_b);
	ft_putstr("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate (stack_a);
	reverse_rotate (stack_b);
	ft_putstr("rrr\n");
}
