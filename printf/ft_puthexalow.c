/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexalow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:55:44 by rbenmakh          #+#    #+#             */
/*   Updated: 2023/12/03 12:33:07 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_puthexa_low(unsigned int num, int first, int *i)
{
	char	key[17];
	int		remainder;

	ft_strlcpy(key, "0123456789ABCDEF", 17);
	if (!num && first == 0)
	{
		ft_putchar('0', i);
	}
	remainder = num % 16;
	if (num)
	{
		ft_puthexa_low(num / 16, 1, i);
		ft_putchar(key[remainder], i);
	}
}
// int main()
// {
// 	int i = 0;
// 	ft_puthexa_low(1234, 1, &i);
// }