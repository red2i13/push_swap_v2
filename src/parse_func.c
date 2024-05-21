/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:18:26 by rbenmakh          #+#    #+#             */
/*   Updated: 2024/05/21 15:18:30 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_read(char **av, t_list **stack_a, int ac)
{
	char	**arr;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		arr = ft_split(av[i], ' ');
		if (!arr || !arr[0])
			return (ft_free_arr(arr), 1);
		j = 0;
		if (enqeue(arr[j], stack_a))
		{
			ft_free_arr(arr);
			return (1);
		}
		ft_free_arr(arr);
		i++;
	}
	return (0);
}

int	is_duplicated(t_list *tmp)
{
	t_list	*tmp1;

	tmp1 = tmp;
	while (tmp)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if ((*(int *)tmp->content) == (*(int *)tmp1->content))
				return (1);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	selection_sort(int *num, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < size)
	{
		j = i;
		while (j > 0 && num[j - 1] > num[j])
		{
			tmp = num[j];
			num[j] = num[j - 1];
			num[j - 1] = tmp;
			j--;
		}
		i++;
	}
	return (0);
}
