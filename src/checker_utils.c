#include "../includes/push_swap.h"

int	is_sorted(t_list *stack)
{
	int	num;
	int	compare;

	if (!stack)
		return (1);
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

long	f_atoi(const char *nptr)
{
	int		i;
	long	result;
	int		sign;

	sign = 1;
	i = 0;
	result = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign = (-1 * (nptr[i] == '-')) + (1 * (nptr[i] == '+'));
		i++;
		if (!nptr[i])
			return (LONG_MAX - 1);
	}
	if ((nptr[i] && !ft_isdigit(nptr[i])) || !nptr[i])
		return (LONG_MAX - 1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
		if ((nptr[i] && !ft_isdigit(nptr[i])) || result * sign > INT_MAX
			|| result * sign < INT_MIN)
			return (LONG_MAX - 1);
	}
	return (result * sign);
}
