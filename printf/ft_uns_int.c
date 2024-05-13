/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:11:06 by rbenmakh          #+#    #+#             */
/*   Updated: 2023/12/02 22:01:10 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uns_int(unsigned int n, int *i)
{
	if (n > 9)
	{
		ft_uns_int(n / 10, i);
		ft_uns_int(n % 10, i);
	}
	else
	{
		ft_putchar(n + 48, i);
	}
}
