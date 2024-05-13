/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:53:49 by rbenmakh          #+#    #+#             */
/*   Updated: 2024/02/09 16:46:38 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c);
	else if (ft_isalpha(c))
		return (c -= 32);
	return (c);
}
