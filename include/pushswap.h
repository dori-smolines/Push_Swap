/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smolines <smolines@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:52:59 by smolines          #+#    #+#             */
/*   Updated: 2024/06/03 16:52:59 by smolines         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				position;
	int				index;
	struct s_list	*target;
	struct s_list	*next;
	int				target_index;
	int				above_median;
	int				push_cost;
	int				ischeapest;
}	t_list;

//util
int		ft_strlen(char *s);
void	ft_putstr(char *s);
int		ft_lstsize(t_list *lst);
int		stack_is_sorted(t_list *lst);
int		ft_atol(char *nptr, char **tabsplit, t_list *stack_a);
char	**ft_split(char const *str, char c);

// parsing

int		ft_lst_no_dble(t_list *lst, int n, char **tabsplit, t_list *stack_a);
int		limit_int(char *tab, char **tabsplit, t_list *stack_a);
void	check_cher(int argc, char **argv, int i);
void	*add_new_node(t_list *new_node, t_list **stack_a);
t_list	*ft_initialisation(int argc, char **argv, t_list *stack_a, int i);

// parsing_util
int		ft_is_space(char c);
int		ft_is_digit(char c);
int		ft_is_sign(char c);
int		ft_is_authorized(char c);
int		ft_parsingerror(char *str);

// parsing_util
int		ft_forbiddenchar(char *str);

// create lst
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstbeforelast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

//manipulations
void	swap(t_list **lst);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_1, t_list **stack_2);
void	pa(t_list **stack_1, t_list **stack_2);
void	pb(t_list **stack_1, t_list **stack_2);
void	rotate(t_list **lst);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **lst);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

// index position and find
int		ft_index(t_list *lst);
int		refresh_position(t_list *lst);
t_list	*find_min(t_list *lst);
t_list	*find_max(t_list *lst);
void	find_target(t_list *stack_a, t_list *stack_b);

// cost
void	refresh_nodes(t_list *stack_a, t_list *stack_b);
void	calculate_cost(t_list *stack_a, t_list *stack_b);
t_list	*find_cheapest_node(t_list *stack_b);
int		sort_three_stacka(t_list **lst);

// move stack
void	rotation_a(t_list **stack_a, t_list *target_node);
void	rotation_b(t_list **stack_b, t_list *cheapest_node);
void	rotation_both(t_list **stack_a,
			t_list **stack_b, t_list *cheapest_node);
void	rev_rotation_both(t_list **stack_a,
			t_list **stack_b, t_list *cheapest_node);
void	move_to_push(t_list **stack_a, t_list **stack_b);

// push_swap
void	finish_sort_a(t_list **stack_a);
void	push_swap(t_list **stack_a, t_list **stack_b);
int		sort(t_list **stack_a, t_list **stack_b, int len_a);

// error and free
void	ft_error(void);
void	free_tab(char **tab);
void	free_lst(t_list **lst);
void	ft_error_tab_lst(char **tabsplit, t_list *stack_a);

#endif
