/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:18:08 by rbenmakh          #+#    #+#             */
/*   Updated: 2024/05/21 15:18:10 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_list **stack_b, bool flag)
{
	void	*num;

	if (!(*stack_b))
		return ;
	num = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = num;
	if (flag == true)
		ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b, bool flag)
{
	if (!(*stack_a) || !(*stack_b))
		return ;
	sa(stack_a, false);
	sb(stack_b, false);
	if (flag == true)
		ft_printf("ss\n");
}

void	ra(t_list **stack_a, bool flag)
{
	t_list	*first;
	t_list	*last;

	if (!(*stack_a))
		return ;
	first = *stack_a;
	last = ft_lstlast(*stack_a);
	*stack_a = (*stack_a)->next;
	first->next = NULL;
	last->next = first;
	if (flag == true)
		ft_printf("ra\n");
}

void	rb(t_list **stack_b, bool flag)
{
	t_list	*first;
	t_list	*last;

	first = *stack_b;
	last = ft_lstlast(*stack_b);
	if (!(*stack_b))
		return ;
	*stack_b = (*stack_b)->next;
	first->next = NULL;
	last->next = first;
	if (flag == true)
		ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b, bool flag)
{
	if (!(*stack_a) || !(*stack_b))
		return ;
	ra(stack_a, false);
	rb(stack_b, false);
	if (flag == true)
		printf("rr\n");
}
