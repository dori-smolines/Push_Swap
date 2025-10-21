/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:49:45 by smolines          #+#    #+#             */
/*   Updated: 2024/06/04 20:15:53 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// inclure nouvel element a la pile
t_list	*ft_lstnew(int value)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);
	new_elem->value = value;
	new_elem->next = NULL;
	new_elem->target = NULL;
	return (new_elem);
}

// trouver le dernier element d'une liste
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// trouver l'avant dernier element d'une liste
t_list	*ft_lstbeforelast(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

// ajouter un nouvel element a la fin d'une liste
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastposition;

	if (!new)
		return ;
	if (*lst)
	{
		lastposition = ft_lstlast(*lst);
		lastposition->next = new;
	}
	if (!(*lst))
		*lst = new;
}

// ajouter un element en debut de liste
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
