/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:50:17 by smolines          #+#    #+#             */
/*   Updated: 2024/06/04 20:16:51 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// check for double and exit if one is found
int	ft_lst_no_dble(t_list *lst, int n, char **tabsplit, t_list *stack_a)
{
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		if (lst->value != n)
			lst = lst->next;
		else
		{
			free_tab(tabsplit);
			free_lst (&stack_a);
			ft_error ();
		}
	}
	return (0);
}

// test limit long int
int	limit_int(char *tab, char **tabsplit, t_list *stack_a)
{
	int	lentab;
	int	j;

	if (!tab)
		return (1);
	j = 1;
	lentab = ft_strlen(tab);
	if (lentab == 0)
		return (1);
	if ((tab[0] == '+') || (tab[0] == '-') || (tab[0] == '0'))
		lentab -= 1;
	while (tab[j] == '0')
	{
		lentab -= 1;
		j++;
	}
	if (lentab > 11)
	{
		free_tab(tabsplit);
		free_lst(&stack_a);
		ft_error();
	}
	return (0);
}

void	check_cher(int argc, char **argv, int i)
{
	while (i < argc)
	{
		ft_forbiddenchar (argv[i]);
		i++;
	}
}

void	*add_new_node(t_list *new_node, t_list **stack_a)
{
	if (!new_node)
		return (NULL);
	ft_lstadd_back(&(*stack_a), new_node);
	return (new_node);
}

t_list	*ft_initialisation(int argc, char **argv, t_list *stack_a, int i)
{
	int		j;
	char	**tab;

	check_cher(argc, argv, i);
	while (i < argc)
	{
		tab = ft_split (argv[i], ' ');
		if (tab == 0)
			exit (1);
		j = 0;
		while (tab[j])
		{
			if (limit_int(tab[j], tab, stack_a) == 1)
				return (free_tab (tab), NULL);
			ft_lst_no_dble(stack_a, ft_atol(tab[j], tab, stack_a),
				tab, stack_a);
			if (!add_new_node(ft_lstnew(ft_atol(tab[j], tab, stack_a))
					, &stack_a))
				return (free_tab(tab), NULL);
			j++;
		}
		free_tab(tab);
	i++;
	}
	return (stack_a);
}
