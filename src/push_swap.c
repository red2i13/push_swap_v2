/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:18:33 by rbenmakh          #+#    #+#             */
/*   Updated: 2024/05/21 15:18:35 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*int_arr(t_list *stack)
{
	int	size;
	int	*arr;
	int	i;

	i = 0;
	size = ft_lstsize(stack);
	arr = (int *)malloc(sizeof(int) * size);
	while (stack)
	{
		arr[i] = *(int *)stack->content;
		stack = stack->next;
		i++;
	}
	return (arr);
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		free(lst->content);
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

int	enqeue(char *n_parse, t_list **stack_a)
{
	long	num;
	int		*num_ptr;

	num = f_atoi(n_parse);
	num_ptr = malloc(sizeof(int));
	if (num_ptr == NULL || num == LONG_MAX - 1)
	{
		return (free(num_ptr), 1);
	}
	*num_ptr = num;
	ft_lstadd_back(&(*stack_a), ft_lstnew(num_ptr));
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*arr;

	(void)av;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (1);
	if (ft_read(av, &stack_a, ac) || is_duplicated(stack_a))
	{
		ft_free_list(stack_a);
		return (write(2, "Error\n", 6), 1);
	}
	arr = int_arr(stack_a);
	algo_start(&stack_a, &stack_b, arr);
	ft_free_list(stack_a);
	ft_free_list(stack_b);
	free(arr);
}
