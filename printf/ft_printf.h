/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:10:58 by rbenmakh          #+#    #+#             */
/*   Updated: 2023/12/03 12:34:16 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *format, ...);
void	ft_putadd(void *ptr, int *i);
void	ft_puthexa_low(unsigned int num, int first, int *i);
void	ft_puthexa_upper(unsigned int num, int first, int *i);
void	ft_printfstr(char *str, int *i);
void	ft_putchar(char c, int *i);
void	ft_putnbr(int n, int *i);
void	ft_uns_int(unsigned int n, int *i);

#endif
