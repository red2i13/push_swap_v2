/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenmakh <rbenmakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 22:51:54 by rbenmakh          #+#    #+#             */
/*   Updated: 2024/02/09 16:44:57 by rbenmakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && lst->content)
	{
		(*del)(lst->content);
		free(lst);
	}
}
