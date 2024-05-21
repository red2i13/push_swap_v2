/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:16:21 by rbenmakh          #+#    #+#             */
/*   Updated: 2024/05/21 15:16:23 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_threee(t_list **stack, int min, int max)
{
	min = min_max(*stack, 0);
	max = min_max(*stack, 1);
	while (is_sorted(*stack))
	{
		if (*(int *)(*stack)->next->content == max)
		{
			rra(stack, true);
			continue ;
		}
		else if ((*(int *)(*stack)->next->next->content == max
			&& *(int *)(*stack)->next->content == min)
			|| (*(int *)(*stack)->content == max
				&& *(int *)(*stack)->next->next->content == min))
		{
			sa(stack, true);
			continue ;
		}
		else if ((*(int *)(*stack)->content == max
			&& *(int *)(*stack)->next->content == min))
		{
			ra(stack, true);
			continue ;
		}
	}
	init_index(stack);
}

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	find_min(stack_a, stack_b, 0);
	init_index(stack_a);
	find_min(stack_a, stack_b, 1);
	ft_sort_threee(stack_a, 0, 0);
	if (*(int *)(*stack_b)->content > *(int *)(*stack_b)->next->content)
		pa(stack_a, stack_b, true);
	else
	{
		rb(stack_b, true);
		pa(stack_a, stack_b, true);
	}
	pa(stack_a, stack_b, true);
}

void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	find_min(stack_a, stack_b, 0);
	ft_sort_threee(stack_a, 0, 0);
	pa(stack_a, stack_b, true);
}

void	algo(t_list **stack_a, t_list **stack_b, int len_a, int range)
{
	int	min;

	min = 0;
	while (*stack_a)
	{
		if ((*stack_a)->rank < min)
		{
			min++;
			pb(stack_a, stack_b, true);
			rb(stack_b, true);
		}
		else if ((*stack_a)->rank <= range + min)
		{
			min++;
			pb(stack_a, stack_b, true);
		}
		else if (still_inrange(*stack_a, range + min) <= len_a / 2)
			ra(stack_a, true);
		else
			rra(stack_a, true);
	}
	final_sort(stack_a, stack_b, len_a - 1);
}

int	algo_start(t_list **stack_a, t_list **stack_b, int *arr)
{
	int	len_a;
	int	range;

	len_a = ft_lstsize(*stack_a);
	range = ft_sqrt(len_a) * 3 / 2;
	selection_sort(arr, len_a);
	init_idx_rank(stack_a, arr, len_a);
	if (len_a == 5)
		return (ft_sort_five(stack_a, stack_b), 0);
	else if (len_a == 4)
		return (ft_sort_four(stack_a, stack_b), 0);
	else if (len_a == 3)
		return (ft_sort_threee(stack_a, 0, 0), 0);
	else if (len_a == 2)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			sa(stack_a, true);
		return (0);
	}
	algo(stack_a, stack_b, len_a, range);
	return (0);
}
