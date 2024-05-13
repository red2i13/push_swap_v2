/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:53:41 by rbenmakh          #+#    #+#             */
/*   Updated: 2024/02/09 16:46:35 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_tolower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c);
	else if (ft_isalpha(c))
		return (c += 32);
	return (c);
}
