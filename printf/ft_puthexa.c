/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:21 by rbenmakh          #+#    #+#             */
/*   Updated: 2023/12/03 12:33:02 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_puthexa_upper(unsigned int num, int first, int *i)
{
	char	key[17];
	int		remainder;

	ft_strlcpy(key, "0123456789ABCDEF", 17);
	remainder = num % 16;
	if (!num && first == 0)
	{
		ft_putchar('0', i);
	}
	if (num)
	{
		ft_puthexa_upper(num / 16, 1, i);
		ft_putchar(key[remainder], i);
	}
}
