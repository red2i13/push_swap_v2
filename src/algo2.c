/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:16:33 by rbenmakh          #+#    #+#             */
/*   Updated: 2024/05/21 15:16:38 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_min(t_list **stack_a, t_list **stack_b, int rank)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->rank == rank)
		{
			rot_max(stack_a, tmp->pos);
			pb(stack_a, stack_b, true);
		}
		tmp = tmp->next;
	}
}

t_list	*find_max(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*max;

	tmp = *stack_b;
	max = *stack_b;
	while (tmp)
	{
		if (*(int *)tmp->content > *(int *)max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	rot_max(t_list **stack_a, int pos)
{
	int	len;
	int	i;

	len = ft_lstsize(*stack_a);
	i = pos * (pos <= len / 2) + (len - pos) * (pos > len / 2);
	while (i)
	{
		if (pos <= len / 2)
			ra(stack_a, true);
		else
			rra(stack_a, true);
		i--;
	}
}

void	final_sort(t_list **stack_a, t_list **stack_b, int max_i)
{
	t_list	*max;
	int		len_b;

	len_b = max_i + 1;
	while (*stack_b)
	{
		max = find_max(stack_b);
		init_index(stack_b);
		while (*stack_b != max)
		{
			if (max->pos > len_b / 2)
				rrb(stack_b, true);
			else
				rb(stack_b, true);
		}
		pa(stack_a, stack_b, true);
		len_b--;
	}
}

int	still_inrange(t_list *stack, int range)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->rank < range)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}
