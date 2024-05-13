/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:18:59 by rbenmakh          #+#    #+#             */
/*   Updated: 2023/12/03 12:32:56 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printhex(unsigned long long num, int *i)
{
	char	key[17];
	int		remainder;

	ft_strlcpy(key, "0123456789ABCDEF", 17);
	remainder = num % 16;
	if (num)
	{
		ft_printhex(num / 16, i);
		ft_putchar(key[remainder], i);
	}
}

void	ft_putadd(void *ptr, int *i)
{
	unsigned long long	p;

	if (!ptr)
	{
		write(1, "(nil)", 6);
		*i += 5;
		return ;
	}
	ft_printfstr("0x", i);
	p = (unsigned long long)ptr;
	ft_printhex(p, i);
}
