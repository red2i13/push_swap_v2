/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:18:38 by rbenmakh          #+#    #+#             */
/*   Updated: 2024/05/21 15:19:26 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_cal(int num, int index)
{
	if (index == 0)
		return (1);
	return (num * ft_cal(num, index - 1));
}

int	ft_sqrt(int num)
{
	int	i;
	int	tmp;

	i = 1;
	while (i < num / 2)
	{
		tmp = ft_cal(i, 2);
		if (tmp > num)
			break ;
		i++;
	}
	return (i - 1);
}

int	find_num(int num, int *arr, int size)
{
	int	min;
	int	max;
	int	mid;

	min = 0;
	max = size - 1;
	while (min <= max)
	{
		mid = min + (max - min) / 2;
		if (arr[mid] == num)
			return (mid);
		else if (arr[mid] < num)
			min = mid + 1;
		else if (arr[mid] > num)
			max = mid - 1;
	}
	return (-1);
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
