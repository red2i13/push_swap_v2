/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:58:18 by rbenmakh          #+#    #+#             */
/*   Updated: 2023/12/03 12:23:30 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check(char c, va_list arg, int *i)
{
	if (c == '\0')
		return ;
	else if (c == 'c')
		ft_putchar(va_arg(arg, int), i);
	else if (c == 's')
		ft_printfstr(va_arg(arg, char *), i);
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(arg, int), i);
	else if (c == 'u')
		ft_uns_int(va_arg(arg, unsigned int), i);
	else if (c == 'p')
		ft_putadd(va_arg(arg, void *), i);
	else if (c == 'x')
		ft_puthexa_low(va_arg(arg, unsigned int), 0, i);
	else if (c == 'X')
		ft_puthexa_upper(va_arg(arg, unsigned int), 0, i);
	else if (c == '%')
		ft_putchar('%', i);
	else
		return ;
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		tot;
	va_list	var;

	i = 0;
	tot = 0;
	va_start(var, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		if (format[i] == '%' && format[i + 1] != '\0')
			check(format[++i], var, &tot);
		else
			ft_putchar(format[i], &tot);
		i++;
	}
	va_end(var);
	return (tot);
}
