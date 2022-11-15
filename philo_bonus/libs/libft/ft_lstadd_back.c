/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:02:11 by emarion           #+#    #+#             */
/*   Updated: 2021/10/21 12:43:39 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new && !lst)
		return ;
	else if (!*lst)
		*lst = new;
	else
	{
		ft_lstlast(*lst)->next = new;
		new->next = NULL;
	}
}
