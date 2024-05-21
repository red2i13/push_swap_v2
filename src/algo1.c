/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:16:27 by rbenmakh          #+#    #+#             */
/*   Updated: 2024/05/21 15:16:29 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_index(t_list **stack)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	init_idx_rank(t_list **stack, int *arr, int size)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp->rank = find_num(*(int *)tmp->content, arr, size);
		tmp = tmp->next;
		i++;
	}
}

int	min_max(t_list *stack, int flag)
{
	int	val;
	int	tmp;

	val = *(int *)stack->content;
	stack = stack->next;
	while (stack)
	{
		tmp = *(int *)stack->content;
		if (flag == 0 && val > tmp)
			val = tmp;
		else if (flag == 1 && val < tmp)
			val = tmp;
		stack = stack->next;
	}
	return (val);
}

int	is_sorted(t_list *stack)
{
	int	num;
	int	compare;

	while (stack->next)
	{
		num = *(int *)stack->content;
		compare = *(int *)stack->next->content;
		if (num > compare)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	find_pos(t_list *stack, int rank)
{
	while (stack)
	{
		if (stack->rank == rank)
			return (stack->pos);
		stack = stack->next;
	}
	return (0);
}
