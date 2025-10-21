/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:50:40 by smolines          #+#    #+#             */
/*   Updated: 2024/06/03 16:50:40 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
			i++;
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
}

// taille de la liste
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// check if stack is sorted
int	stack_is_sorted(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		if (lst->value > lst->next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_atol(char *nptr, char **tabsplit, t_list *stack_a)
{
	long long int	i;
	long long int	signe;
	long long int	nombre;

	nombre = 0;
	signe = 1;
	i = 0;
	while (ft_is_space(nptr[i]) == 1)
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		signe = -signe;
		i++;
	}
	while ((nptr[i] > 47) && (nptr[i] < 58))
	{
		nombre = 10 * nombre + nptr[i] - 48;
		i++;
	}
	if (((signe * nombre) < -2147483648) || ((signe * nombre) > 2147483647))
		ft_error_tab_lst (tabsplit, stack_a);
	return ((int)signe * nombre);
}
