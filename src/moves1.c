/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:18:14 by rbenmakh          #+#    #+#             */
/*   Updated: 2024/05/21 15:18:15 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_list **stack_a, bool flag)
{
	t_list	*before_last;
	t_list	*last;
	t_list	*tmp;

	if (!(*stack_a) || ft_lstsize(*stack_a) < 2)
		return ;
	last = ft_lstlast(*stack_a);
	before_last = (*stack_a);
	while (before_last->next->next != NULL)
	{
		before_last = before_last->next;
	}
	before_last->next = NULL;
	tmp = (*stack_a);
	(*stack_a) = last;
	(*stack_a)->next = tmp;
	if (flag == true)
		ft_printf("rra\n");
}

void	rrb(t_list **stack_b, bool flag)
{
	t_list	*before_last;
	t_list	*last;
	t_list	*tmp;

	if (!(*stack_b) || ft_lstsize(*stack_b) < 2)
		return ;
	last = ft_lstlast(*stack_b);
	before_last = (*stack_b);
	while (before_last->next->next != NULL)
	{
		before_last = before_last->next;
	}
	before_last->next = NULL;
	tmp = (*stack_b);
	(*stack_b) = last;
	(*stack_b)->next = tmp;
	if (flag == true)
		ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b, bool flag)
{
	if (!(*stack_a) || !(*stack_b))
		return ;
	rra(stack_a, false);
	rrb(stack_b, false);
	if (flag == true)
		ft_printf("rrr\n");
}

void	pa(t_list **stack_a, t_list **stack_b, bool flag)
{
	t_list	*tmp;

	if (!(*stack_b))
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_a, tmp);
	if (flag == true)
		ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b, bool flag)
{
	t_list	*tmp;

	if (!(*stack_a))
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_b, tmp);
	if (flag == true)
		ft_printf("pb\n");
}
